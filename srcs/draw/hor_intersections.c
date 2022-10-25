/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_intersections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:51:55 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/24 21:33:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_point	*get_first_hor_intersection(t_cub *data,
	t_point *player, t_directions *dir)
{
	t_point		*intersection;
	double		dy;
	double		dx;
	double		angle;

	angle = get_right_angle(data, dir, HOR);
	intersection = malloc(sizeof(t_point));
	if (dir->up == 1)
		intersection->y = (((int)(player->y / 64)) * 64) - 0.000001;
	else
		intersection->y = (((int)(player->y / 64)) * 64) + 64;
	dy = abs_val(player->y - intersection->y);
	dx = dy / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	intersection->x = player->x + dx;
	check_limits(data, intersection);
	return (intersection);
}

void	next_hor_intersection(t_cub *data,
	t_point *intersection, t_directions *dir)
{
	double		dy;
	double		dx;
	double		angle;

	angle = get_right_angle(data, dir, HOR);
	dy = WALLS_SIDE;
	if (dir->up == 1)
		dy *= -1;
	dx = WALLS_SIDE / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	intersection->y += dy;
	intersection->x += dx;
	check_limits(data, intersection);
}

t_point	*check_hor_intersections(t_cub *data,
	t_point *player, t_directions *dir)
{
	t_point	*intersection;

	intersection = get_first_hor_intersection(data, player, dir);
	while (!is_wall(data, intersection))
		next_hor_intersection(data, intersection, dir);
	return (intersection);
}
