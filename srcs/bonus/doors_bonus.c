/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:46:59 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 14:48:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_point	*closest_grid_line(t_cub *data)
{
	t_point			*hor_line;
	t_point			*ver_line;
	double			hor_distance;
	double			ver_distance;
	t_directions	dir;

	get_directions_3d(data, &dir);
	hor_line = get_first_hor_intersection(data, data->player, &dir);
	ver_line = get_first_ver_intersection(data, data->player, &dir);
	hor_distance = get_distance(data->player, hor_line);
	ver_distance = get_distance(data->player, ver_line);
	if (hor_distance < ver_distance)
	{
		free(ver_line);
		data->dist_to_closest_wall = hor_distance;
		return (hor_line);
	}
	else
	{
		free(hor_line);
		data->dist_to_closest_wall = ver_distance;
		return (ver_line);
	}
}

int	closest_wall_is_door(t_cub *data)
{
	t_point	*closest_grid;
	int		x_map;
	int		y_map;

	closest_grid = closest_grid_line(data);
	x_map = closest_grid->x / WALLS_SIDE;
	y_map = closest_grid->y / WALLS_SIDE;
	free(closest_grid);
	if (data->cubmap[y_map][x_map] == 'D' || data->cubmap[y_map][x_map] == 'O')
		return (1);
	return (0);
}

void	open_or_close_door(t_cub *data)
{
	int		x_map;
	int		y_map;
	t_point	*closest_grid;

	closest_grid = closest_grid_line(data);
	x_map = closest_grid->x / WALLS_SIDE;
	y_map = closest_grid->y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'D')
		data->cubmap[y_map][x_map] = 'O';
	else
		data->cubmap[y_map][x_map] = 'D';
	free(closest_grid);
}

void	look_for_door_close(t_cub *data)
{
	if (!closest_wall_is_door(data))
		return ;
	else if (data->dist_to_closest_wall <= DIST_TO_OPEN_DOORS)
		open_or_close_door(data);
}
