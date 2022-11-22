/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:53:14 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/22 17:31:28 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	find_wall(t_cub *data)
{
	double			closest;
	double			wall;
	t_directions	dir;
	t_point			*ver_intersection;
	t_point			*hor_intersection;

	get_directions_3d(data, &dir);
	hor_intersection = check_hor_intersections(data, data->player, &dir);
	ver_intersection = check_ver_intersections(data, data->player, &dir);
	closest = closest_wall(data, hor_intersection, ver_intersection);
	wall = closest * cos(data->ray - data->angle);
	free(hor_intersection);
	free(ver_intersection);
	return (wall);
}

void	draw_wall_slice(t_cub *data, double distance_to_wall, double x)
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
		color = texturing(data, projected_height, y - beginning);
		put_pixel_to_image_3d(data, x, y, color);
	}
}

void	draw_walls(t_cub *data)
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
	draw_wall_slice(data, distance_to_wall, 0);
	fov_ray -= incrementation;
	while (i <= WIDTH_3D)
	{
		data->ray = fov_ray;
		modulo_two_pi(&data->ray);
		distance_to_wall = find_wall(data);
		draw_wall_slice(data, distance_to_wall, i);
		fov_ray -= incrementation;
		i++;
	}
	data->ray = data->angle;
}

int	render_3d(t_cub *data)
{
	lay_background(data);
	draw_walls(data);
	rotation_and_moves(data);
	mlx_put_image_to_window(data->map3d->mlx_ptr, data->map3d->win_ptr,
		data->map3d->img_ptr, 0, 0);
	return (1);
}

void	draw_3d(t_cub *data)
{
	t_mlx	*map3d;

	map3d = malloc(sizeof(t_mlx));
	data->map3d = map3d;
	init_3d_map(data);
	get_map_param(data);
	find_character_in_map(data);
	mlx_loop_hook(map3d->mlx_ptr, &render_3d, data);
	mlx_hook(map3d->win_ptr, 2, 0, key_press, data);
	mlx_hook(map3d->win_ptr, 3, 0, key_release, data);
	mlx_hook(map3d->win_ptr, 17, 1L << 0, red_cross, data);
	mlx_loop(map3d->mlx_ptr);
}
