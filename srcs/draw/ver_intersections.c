/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_intersections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:07 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/24 20:52:48 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	next_ver_intersection(t_cub *data,
	t_point *intersection, t_directions *dir)
{
	double		dx;
	double		dy;
	double		angle;

	angle = get_right_angle(data, dir, VERT);
	dx = 64;
	if (dir->left == 1)
		dx *= -1;
	dy = 64 * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	intersection->x += dx;
	intersection->y += dy;
	check_limits(data, intersection);
}

t_point	*get_first_ver_intersection(t_cub *data,
	t_point *player, t_directions *dir)
{
	t_point		*intersection;
	double		dx;
	double		dy;
	double		angle;

	angle = get_right_angle(data, dir, VERT);
	intersection = malloc(sizeof(t_point));
	if (dir->right == 1)
		intersection->x = (((int)(player->x / WALLS_SIDE)) * WALLS_SIDE)
			+ WALLS_SIDE;
	else
		intersection->x = (((int)(player->x / WALLS_SIDE)) * WALLS_SIDE)
			- 0.000001;
	dx = abs_val(player->x - intersection->x);
	dy = dx * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	intersection->y = player->y + dy;
	check_limits(data, intersection);
	return (intersection);
}

t_point	*check_ver_intersections(t_cub *data,
	t_point *player, t_directions *dir)
{
	t_point	*intersection;

	intersection = get_first_ver_intersection(data, player, dir);
	while (!is_wall(data, intersection))
		next_ver_intersection(data, intersection, dir);
	return (intersection);
}
