/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:03:44 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/24 16:14:14 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_collisions(t_cub *data, float x, float y, int direction)
{
	int	map_x;
	int	map_y;
	
	map_y = get_y_coordinate(data, y);
	map_x = get_x_coordinate(data, x, map_y);
	if ((((int)(x) + 1) % 64 != 0) && (((int)(y) + 1) % 64 != 0))
		return (0);
	if (((int)(x) + 1) % 64 == 0)
	{
		if (direction == RIGHT)
			map_x++;
		if (data->cubmap[map_y][map_x] == '1')
			return (1);
	}
	if (((int)(y) + 1) % 64 == 0)
	{
		if (direction == DOWN)
			map_y++;
		if (data->cubmap[map_y][map_x] == '1')
			return (1);
	}
	return (0);
}

int	rotation_and_moves(int keycode, t_cub *data)
{
	if (keycode == LEFT_ARROW)
		data->angle += 0.05;
	else if (keycode == RIGHT_ARROW)
		data->angle -= 0.05;
	if (keycode == W_KEY)
	{
		if (!check_collisions(data, data->poz[0], data->poz[1] - 6, UP))
			data->poz[Y] -= 1;
	}
	if (keycode == S_KEY)
	{
		if (!check_collisions(data, data->poz[0], data->poz[1] + 6, DOWN))
			data->poz[Y] += 1;
	}
	if (keycode == D_KEY)
	{
		if (!check_collisions(data, data->poz[0] + 6, data->poz[1], RIGHT))
			data->poz[X] += 1;
	}
	if (keycode == A_KEY)
	{
		if (!check_collisions(data, data->poz[0] - 6, data->poz[1], LEFT))
			data->poz[X] -= 1;
	}
	draw_map(data);
	draw_character(data);
	paint_fov(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	return (0);
}