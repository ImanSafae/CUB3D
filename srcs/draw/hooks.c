/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:03:44 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/19 21:37:48 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rotation_and_moves(int keycode, t_cub *data)
{
	if (keycode == LEFT_ARROW)
		data->angle += 0.05;
	else if (keycode == RIGHT_ARROW)
		data->angle -= 0.05;
	draw_map(data);
	show_character(data);
	paint_fov(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr, data->mlx->img_ptr, 0, 0);
	return (0);
}