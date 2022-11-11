/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:29:16 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 18:15:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	get_random_painting(t_cub *data, int index)
{
	t_img	texture;

	if (index == RANDOM1)
		texture = data->painting_textures[0];
	else if (index == RANDOM2)
		texture = data->painting_textures[1];
	else if (index == RANDOM3)
		texture = data->painting_textures[2];
	else if (index == RANDOM4)
		texture = data->painting_textures[3];
	else if (index == RANDOM5)
		texture = data->painting_textures[4];
	else if (index == RANDOM6)
		texture = data->painting_textures[5];
	else if (index == RANDOM7)
		texture = data->painting_textures[6];
	else
		texture = data->painting_textures[7];
	return (texture);
}

int	wall_orientation_bonus(t_cub *data)
{
	t_directions	dir;
	int				orientation;
	int				door_or_special;

	get_directions_3d(data, &dir);
	door_or_special = check_for_door_or_special_txtr(data);
	if (door_or_special != 0)
		return (door_or_special);
	if (data->closest_wall == HOR)
	{
		if (dir.up == 1)
			orientation = NO;
		else
			orientation = SO;
	}
	else
	{
		if (dir.right == 1)
			orientation = EA;
		else
			orientation = WE;
	}
	return (orientation);
}

t_img	assign_texture(t_cub *data)
{
	int		orientation;
	t_img	texture;

	orientation = wall_orientation_bonus(data);
	if (orientation == RANDOM1 || orientation == RANDOM2
		|| orientation == RANDOM3 || orientation == RANDOM4
		|| orientation == RANDOM5 || orientation == RANDOM6
		|| orientation == RANDOM7 || orientation == RANDOM8)
		texture = get_random_painting(data, orientation);
	else
		texture = data->textures[orientation];
	return (texture);
}

unsigned int	texturing_bonus(t_cub *data,
	double projected_height, double y_wall)
{
	unsigned int	texture_pixel;
	t_img			texture;
	int				texture_x;
	int				texture_y;

	texture = assign_texture(data);
	if (data->closest_wall == HOR)
		texture_x = (int)(data->intersection.x) % WALLS_SIDE;
	else
		texture_x = (int)(data->intersection.y) % WALLS_SIDE;
	texture_y = (int)(((y_wall - 1) * WALLS_SIDE) / projected_height);
	while (texture_x < 0)
		texture_x++;
	while (texture_y < 0)
		texture_y++;
	texture_pixel = *(unsigned int *)(texture.addr + ((int)texture_y
				* texture.line + (int)texture_x * (texture.bpix / 8)));
	return (texture_pixel);
}
