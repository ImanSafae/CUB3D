/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:53:43 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 02:42:49 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	modulo_two_pi(double *angle)
{
	while ((*angle) > 2 * PI)
		(*angle) = (*angle) - (2 * PI);
	while ((*angle) < 0)
		(*angle) = (2 * PI) + (*angle);
}

double	get_distance(t_point *player, t_point *wall)
{
	double	distance;

	distance = hypot(player->x - wall->x, player->y - wall->y);
	return (abs_val(distance));
}

double	get_right_angle(t_cub *data, t_directions *dir, int grid)
{
	double			angle;

	angle = data->ray;
	if (dir->up == 1 && dir->right == 1 && grid == HOR)
		angle = data->ray;
	if (dir->up == 1 && dir->left == 1 && grid == HOR)
		angle = PI - data->ray;
	if (dir->down == 1 && dir->left == 1 && grid == HOR)
		angle = data->ray - PI;
	if (dir->down == 1 && dir->right == 1 && grid == HOR)
		angle = (2 * PI) - data->ray;
	if (dir->up == 1 && dir->right == 1 && grid == VERT)
		angle = data->ray;
	if (dir->up == 1 && dir->left == 1 && grid == VERT)
		angle = PI - data->ray;
	if (dir->down == 1 && dir->left == 1 && grid == VERT)
		angle = data->ray - PI;
	if (dir->down == 1 && dir->right == 1 && grid == VERT)
		angle = (2 * PI) - data->ray;
	return (angle);
}

void	check_limits(t_cub *data, t_point *point)
{
	if (point->x < 0)
		point->x = 0;
	if (point->y < 0)
		point->y = 0;
	if (point->x > data->map_len)
		point->x = data->map_len - WALLS_SIDE;
	if (point->y > data->map_height)
		point->y = data->map_height - WALLS_SIDE;
}

int	is_wall(t_cub *data, t_point *point)
{
	int	x;
	int	y;

	y = (int)(get_y_coordinate(point->y));
	x = (int)(get_x_coordinate(point->x));
	if (x >= data->map_len / WALLS_SIDE - 1)
		x = (data->map_len / WALLS_SIDE) - 1;
	if (y >= data->map_height / WALLS_SIDE - 1)
		y = (data->map_height / WALLS_SIDE) - 1;
	if (data->cubmap[y][x] == '1' || data->cubmap[y][x] == 'D'
		|| data->cubmap[y][x] == 'R' || data->cubmap[y][x] == 'G')
		return (1);
	return (0);
}
