/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:29:16 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 02:41:42 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	textures_rng(t_cub *data)
{
	int	i;
	int	j;
	int	randint;

	i = 0;
	j = 0;
	while (data->cubmap && data->cubmap[i])
	{
		while (data->cubmap[i][j])
		{
			randint = rand() % 14;
			if (randint == 0 && data->cubmap[i][j] == '1')
				data->cubmap[i][j] = 'R';
			j++;
		}
		i++;
		j = 0;
		
	}
}

int	check_for_door_or_special_txtr(t_cub *data)
{
	int	x_map;
	int	y_map;

	x_map = data->intersection.x / WALLS_SIDE;
	y_map = data->intersection.y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'D')
		return (DOOR);
	else if (data->cubmap[y_map][x_map] == 'G')
		return (END);
	else if (data->cubmap[y_map][x_map] == 'R')
		return (RANDOM);
	return (0);
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

unsigned int	texturing_bonus(t_cub *data, double projected_height, double y_wall)
{
	unsigned int	texture_pixel;
	t_img			texture;
	int				orientation;
	int				texture_x;
	int				texture_y;


	orientation = wall_orientation_bonus(data);
	texture = data->textures[orientation];
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
