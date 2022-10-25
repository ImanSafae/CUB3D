/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:01 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/25 01:29:37 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	init_character_in_mini(t_cub *data, int x, int y)
// {
// 	// data->mini_playr.x = (double)((x * MINI_RATIO) + 5);
// 	// data->mini_playr.y = (double)((y * MINI_RATIO) + 5);
// 	data->mini_playr.x = data->player->x / 64 * MINI_RATIO;
// 	data->mini_playr.y = data->player->y / 64 * MINI_RATIO;
// }

void	find_character_in_map_bonus(t_cub *data)
{
	int		x_map;
	int		y_map;
	bool	found;

	x_map = 0;
	y_map = 0;
	found = false;
	while (y_map < data->map_height)
	{
		while (x_map < ft_strlen(data->cubmap[y_map]))
		{
			if (is_persona(data->cubmap[y_map][x_map], OPEN))
			{
				found = true;
				break ;
			}
			x_map++;
		}
		if (found == true)
			break ;
		x_map = 0;
		y_map++;
	}
	init_character_pos(data, x_map, y_map);
	// init_character_in_mini(data, x_map, y_map);
}

// void	paint_ray(t_cub *data)
// {
// 	t_directions	*dir;
// 	double			hor_distance;
// 	double			ver_distance;
// 	t_point			*hor_intersection;
// 	t_point			*ver_intersection;

// 	dir = get_directions(data);
// 	hor_intersection = check_hor_intersections(data, data->player, dir);
// 	hor_distance = get_distance(data->player, hor_intersection);
// 	ver_intersection = check_ver_intersections(data, data->player, dir);
// 	ver_distance = get_distance(data->player, ver_intersection);
// 	if (ver_distance < hor_distance)
// 		dda(data, *data->player, *ver_intersection, RED);
// 	else
// 		dda(data, *data->player, *hor_intersection, GREEN);
// 	free(dir);
// 	free(hor_intersection);
// 	free(ver_intersection);
// }

// void	paint_fov(t_cub *data)
// {
// 	double	fov_ray;
// 	double	incr;

// 	modulo_two_pi(&data->angle);
// 	fov_ray = data->angle + 0.52;
// 	incr = 1.05 / 320;
// 	data->ray = fov_ray;
// 	modulo_two_pi(&data->ray);
// 	paint_ray(data);
// 	fov_ray = fov_ray - incr;
// 	while (fov_ray > data->angle - 0.52)
// 	{
// 		data->ray = fov_ray;
// 		modulo_two_pi(&data->ray);
// 		paint_ray(data);
// 		fov_ray = fov_ray - incr;
// 	}
// 	data->ray = data->angle - 0.52;
// 	modulo_two_pi(&data->ray);
// 	paint_ray(data);
// 	data->ray = data->angle;
// }

t_directions	*get_directions(t_cub *data)
{
	t_directions	*dir;

	dir = malloc(sizeof(t_directions));
	dir->down = 0;
	dir->up = 0;
	dir->left = 0;
	dir->right = 0;
	if (data->ray > 0 && data->ray < PI)
		dir->up = 1;
	else
		dir->down = 1;
	if ((data->ray > 0 && data->ray < PI / 2)
		|| (data->ray > 3 * PI / 2 && data->ray < 2 * PI))
		dir->right = 1;
	else
		dir->left = 1;
	return (dir);
}
