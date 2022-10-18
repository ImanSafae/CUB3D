/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/11 19:40:37 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_character(t_cub *data)
{
	int	i;
	int	j;

	i = data->player->x - 4;
	j = data->player->y - 4;
	while (j <= data->player->y + 5)
	{
		while (i <= data->player->x + 5)
		{
			put_pixel_to_image(data, i, j, YELLOW);
			i++;
		}
		i = data->player->x - 5;
		j++;
	}
}

void	paint_wall_or_space(t_cub *data, int x_pixel, int y_pixel)
{
	int	x;
	int	y;

	y = get_y_coordinate(y_pixel);
	x = get_x_coordinate(x_pixel);
	if ((data->cubmap[y][x] == '0') || is_persona(data->cubmap[y][x], OPEN))
		put_pixel_to_image(data, x_pixel, y_pixel, WHITE);
	else
		put_pixel_to_image(data, x_pixel, y_pixel, GREY);
}

void	draw_map(t_cub *cub)
{
	int	i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y < cub->map_height)
	{
		while (i_x < cub->map_len)
		{
			if ((i_x + 1) % 64 == 0 || (i_y + 1) % 64 == 0)
				put_pixel_to_image(cub, i_x, i_y, BLACK);
			else
				paint_wall_or_space(cub, i_x, i_y);
			i_x++;
		}
		i_x = 0;
		i_y++;
	}
}

int		render_2d(t_cub *data)
{
	draw_map(data);
	paint_fov(data);
	draw_character(data);
	mlx_put_image_to_window(data->mini->mlx_ptr, data->mini->win_ptr, data->mini->img_ptr, 0, 0);
	return (1);
}


void	draw2d(t_cub *cub)
{
	t_mlx	*m;

	m = cub->mini;
	get_map_param(cub);
	init_window(&cub, cub->map_len, cub->map_height);
	init_character(cub);
	// mlx_key_hook(m->win_ptr, rotation_and_moves, cub);
	render_2d(cub);
	mlx_hook(m->win_ptr, 2, 0, rotation_and_moves, cub);
	// mlx_loop_hook(m->mlx_ptr, &render_2d, cub);
	// printf("closest wall = %d\n", find_closest_hor_wall(cub, (int)(cub->poz[0]), (int)(cub->poz[0]), RIGHT));
	mlx_loop(m->mlx_ptr);
}
