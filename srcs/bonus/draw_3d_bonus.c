/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:38:16 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/25 01:36:13 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_3d_bonus(t_cub *data)
{
	lay_background(data);
	draw_walls(data);
	draw_map(data);
	draw_character(data);
	bonus_moves(data);
	mlx_put_image_to_window(data->map3d->mlx_ptr, data->map3d->win_ptr,
		data->map3d->img_ptr, 0, 0);
	return (1);
}

void	draw_3d_bonus(t_cub *data)
{
	t_mlx	*map3d;

	map3d = malloc(sizeof(t_mlx));
	data->map3d = map3d;
	data->mini_width = data->map_len * MINI_RATIO;
	data->mini_height = data->map_height * MINI_RATIO;
	parse_txtur(data);
	init_3d_map(data);
	get_map_param(data);
	find_character_in_map_bonus(data);
	mlx_loop_hook(map3d->mlx_ptr, &render_3d_bonus, data);
	mlx_hook(map3d->win_ptr, 2, 0, key_press_bonus, data);
	mlx_hook(map3d->win_ptr, 3, 0, key_release_bonus, data);
	mlx_loop(map3d->mlx_ptr);
}
