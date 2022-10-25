/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:51:00 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/25 02:48:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	texturing(t_cub *data, double projected_height, double y_wall)
{
	unsigned int	texture_pixel;
	t_img			texture;
	int				orientation;
	int				texture_x;
	int				texture_y;

	orientation = wall_orientation(data);
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_floor_or_ceiling_color(t_cub *data, int floor_or_ceiling)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	if (floor_or_ceiling != FLOOR && floor_or_ceiling != CEILING)
	{
		ft_putstr_fd("Error with floor/ceiling color:", 2);
		ft_putstr_fd("trying to access nonexisting memory space.\n", 2);
		exit(EXIT_FAILURE);
	}
	red = data->rgb[floor_or_ceiling][0];
	green = data->rgb[floor_or_ceiling][1];
	blue = data->rgb[floor_or_ceiling][2];
	color = create_trgb(0, red, green, blue);
	return (color);
}

int	check_for_door(t_cub *data)
{
	int	x_map;
	int	y_map;

	x_map = data->intersection.x / 64;
	y_map = data->intersection.y / 64;
	if (data->cubmap[y_map][x_map] == 'D')
		return (1);
	return (0);
}

int	wall_orientation(t_cub *data)
{
	t_directions	dir;
	int				orientation;

	get_directions_3d(data, &dir);
	if (check_for_door(data))
		return (DOOR);
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
