/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:38:16 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 02:27:25 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall_slice_bonus(t_cub *data, double distance_to_wall, double x)
{
	double				projected_height;
	double				beginning;
	double				y;
	double				end;
	unsigned int		color;

	projected_height = WALLS_SIDE / (1 + distance_to_wall) * DIST_TO_PLANE;
	beginning = ((HEIGHT_3D - projected_height) / 2) - 1;
	y = beginning - 1;
	end = projected_height + beginning;
	if (projected_height > HEIGHT_3D)
	{
		y = beginning + ((projected_height - HEIGHT_3D) / 2) - 1;
		end = projected_height - ((projected_height - HEIGHT_3D) / 2);
	}
	while (y < end)
	{
		y++;
		if ((x < 0 || y < 0 || x > WIDTH_3D - 1 || y > HEIGHT_3D - 1))
			continue ;
		color = texturing_bonus(data, projected_height, y - beginning);
		put_pixel_to_image_3d(data, x, y, color);
	}
}

void	draw_walls_bonus(t_cub *data)
{
	double	i;
	double	distance_to_wall;
	double	incrementation;
	double	fov_ray;

	i = 1;
	modulo_two_pi(&data->angle);
	fov_ray = data->angle + (PI / 6);
	incrementation = (PI / 3) / WIDTH_3D;
	data->ray = fov_ray;
	modulo_two_pi(&data->ray);
	distance_to_wall = find_wall(data);
	draw_wall_slice_bonus(data, distance_to_wall, 0);
	fov_ray -= incrementation;
	while (i <= WIDTH_3D)
	{
		data->ray = fov_ray;
		modulo_two_pi(&data->ray);
		distance_to_wall = find_wall(data);
		draw_wall_slice_bonus(data, distance_to_wall, i);
		fov_ray -= incrementation;
		i++;
	}
	data->ray = data->angle;
}

int	render_3d_bonus(t_cub *data)
{
	lay_background(data);
	draw_walls_bonus(data);
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
