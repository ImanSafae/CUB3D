/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:53:14 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/19 00:57:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	find_wall(t_cub *data)
{
	double			wall;
	t_point			*ver_intersection;
	t_point			*hor_intersection;
	t_directions	dir;
	double			hor_distance;
	double			ver_distance;

	get_directions_3d(data, &dir);
	// on caste UN seul rayon et on checke sur les intersections du grid si on rencontre un mur
	hor_intersection = check_hor_intersections(data, data->player, &dir);
	ver_intersection = check_ver_intersections(data, data->player, &dir);
	hor_distance = get_distance(data->player, hor_intersection);
	ver_distance = get_distance(data->player, ver_intersection);
	if (hor_distance < ver_distance)
	{
		wall = hor_distance * cos(data->ray - data->angle);
		data->closest_wall = HOR;
		data->intersection.x = hor_intersection->x;
		data->intersection.y = hor_intersection->y;
	}
	else
	{
		wall = ver_distance * cos(data->ray - data->angle);
		data->closest_wall = VERT;
		data->intersection.x = ver_intersection->x;
		data->intersection.y = ver_intersection->y;
	}
	free(hor_intersection);
	free(ver_intersection);
	// free(dir);
	return (wall);
}

void	draw_wall_slice(t_cub *data, double distance_to_wall, double x)
{
	double				projected_height;
	double				beginning;
	double				y;
	unsigned int		color;

	projected_height = 64 / distance_to_wall * DIST_TO_PLANE;
	beginning = ((HEIGHT_3D - projected_height) / 2) - 1; // beginning of the wall column in y coordinate
	y = 0;
	// color = get_wall_color(data);
	while (y < projected_height)
	{
		color = texturing(data, projected_height, y);
		put_pixel_to_image_3d(data, x, y + beginning, color);
		y++;
	}
}

void	draw_walls(t_cub *data)
{
	double	i;
	double	distance_to_wall;
	double	incrementation;
	double	fov_ray; // FOV (field of view) ray

	i = 1;
	modulo_two_pi(&data->angle);
	fov_ray = data->angle + (PI / 6); // direction the player is looking into + 30 degrees (0.52 rad)
	incrementation = (PI / 3) / WIDTH_3D; // "distance" in radians between 2 rays
	data->ray = fov_ray; 
	modulo_two_pi(&data->ray); // makes sure the angle doesn't exceed 2pi
	distance_to_wall = find_wall(data);
	draw_wall_slice(data, distance_to_wall, 0);
	fov_ray -= incrementation;
	while (i <= WIDTH_3D) // this loop is gonna calculate the distance to each one of the WIDTH_3D "slices" of wall
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
	lay_background(data); // sets a grey background
	draw_walls(data);
	rotation_and_moves(data);
	// data->poz[X] += 0.1;
	// data->player->y -= 0.2;
	mlx_put_image_to_window(data->map3d->mlx_ptr, data->map3d->win_ptr, 
		data->map3d->img_ptr, 0, 0);
	return (1);
}

void	draw_3d(t_cub *data)
{
	t_mlx	*map3d;

	map3d = malloc(sizeof(t_mlx));
	data->map3d = map3d;
	parse_txtur(data);
	init_3d_map(data); // initializing all the MLX pointers
	get_map_param(data); // sets the map's real size
	init_character(data); // sets the character's position when simulation begins
	// render_3d(data);
	mlx_loop_hook(map3d->mlx_ptr, &render_3d, data);
	mlx_hook(map3d->win_ptr, 2, 0, key_press, data);
	mlx_hook(map3d->win_ptr, 3, 0, key_release, data);
	// mlx_mouse_hook(map3d->win_ptr, mouse_pov, data);
	// mlx_put_image_to_window(data->map3d->mlx_ptr, data->map3d->win_ptr, data->map3d->img_ptr, 0, 0);
	mlx_loop(map3d->mlx_ptr);
}
