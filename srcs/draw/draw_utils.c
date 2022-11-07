/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:48:21 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/06 23:39:53 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_y_coordinate(double y_pixel)
{
	double	y;

	y = y_pixel / 64;
	return (y);
}

double	get_x_coordinate(double x_pixel)
{
	double	x;

	x = x_pixel / 64;
	return (x);
}

void	put_pixel_to_image_3d(t_cub *data, double x, double y, int color)
{
	char	*pixel;
	int		position;
	t_mlx	*m;

	m = data->map3d;
	if (x < 0 || y < 0 || x > WIDTH_3D - 1 || y > HEIGHT_3D - 1)
		return ;
	position = ((int)x * (m->bpix / 8)) + ((int)y * m->line);
	pixel = m->img_addr + ((int)y * m->line + (int)x * (m->bpix / 8));
	*(unsigned int *)pixel = color;
}

void	get_map_param(t_cub *cub)
{
	cub->map_len *= 64;
	cub->map_height *= 64;
}

// void	init_window(t_cub **data, int length, int height)
// {
// 	t_mlx	*m;

// 	m = (*data)->map3d;
// 	m->mlx_ptr = mlx_init();
// 	m->win_ptr = mlx_new_window(m->mlx_ptr, length, height, "cub3d");
// 	m->img_ptr = mlx_new_image(m->mlx_ptr, length, height);
// 	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix),
// 			&(m->line), &(m->end));
// }
