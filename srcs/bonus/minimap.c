/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/10 18:57:34 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_character(t_cub *data)
{
	int	i;
	int	j;

	data->mini_playr.x = data->player->x / 64 * MINI_RATIO;
	data->mini_playr.y = data->player->y / 64 * MINI_RATIO;
	i = data->mini_playr.x - 2;
	j = data->mini_playr.y - 2;
	while (j <= data->mini_playr.y + 3)
	{
		while (i <= data->mini_playr.x + 3)
		{
			put_pixel_to_image_3d(data, i + 5, j + 10, RED);
			i++;
		}
		i = data->mini_playr.x - 3;
		j++;
	}
}

void	paint_wall_or_space(t_cub *data, int x_pixel, int y_pixel)
{
	int	x;
	int	y;

	y = y_pixel / MINI_RATIO;
	x = x_pixel / MINI_RATIO;
	if ((data->cubmap[y][x] == '0') || (data->cubmap[y][x] == 'O') || is_persona(data->cubmap[y][x], OPEN))
		put_pixel_to_image_3d(data, x_pixel + 5, y_pixel + 10, DARK_PURPLE);
	else if (data->cubmap[y][x] == 'D')
		put_pixel_to_image_3d(data, x_pixel + 5, y_pixel + 10, BLACK);
	else if (data->cubmap[y][x] == 'Z' && data->fake_door_mode == true)
		put_pixel_to_image_3d(data, x_pixel + 5, y_pixel + 10, BLACK);
	else
		put_pixel_to_image_3d(data, x_pixel + 5, y_pixel + 10, PURPLE);
}

void	draw_map(t_cub *cub)
{
	int	i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y < cub->mini_height)
	{
		while (i_x < cub->mini_width)
		{
			paint_wall_or_space(cub, i_x, i_y);
			i_x++;
		}
		i_x = 0;
		i_y++;
	}
}

// int	render_2d(t_cub *data)
// {
// 	draw_map(data);
// 	// paint_fov(data);
// 	draw_character(data);
// 	bonus_moves(data);
// 	mlx_put_image_to_window(data->mini->mlx_ptr, data->mini->win_ptr,
// 		data->mini->img_ptr, 0, 0);
// 	return (1);
// }

// void	draw2d(t_cub *cub)
// {
// 	t_mlx	*m;

// 	m = cub->mini;
// 	cub->mini_width = cub->map_len * MINI_RATIO;
// 	cub->mini_height = cub->map_height * MINI_RATIO;
// 	// get_map_param(cub);
// 	init_window(&cub, cub->mini_width, cub->mini_height);
// 	find_character_in_map_bonus(cub);
// 	mlx_loop_hook(m->mlx_ptr, &render_2d, cub);
// 	mlx_hook(m->win_ptr, 2, 0, key_press, cub);
// 	mlx_hook(m->win_ptr, 3, 0, key_release, cub);
// 	mlx_loop(m->mlx_ptr);
// }
