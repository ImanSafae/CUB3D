/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:51:00 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/20 17:18:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_floor_or_ceiling_color(t_cub *data, int floor_or_ceiling)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	if (floor_or_ceiling != FLOOR && floor_or_ceiling != CEILING)
	{
		ft_putstr_fd("Error with floor/ceiling color: trying to access nonexisting memory space.\n", 2);
		exit(EXIT_FAILURE);
	}
	red = data->rgb[floor_or_ceiling][0];
	green = data->rgb[floor_or_ceiling][1];
	blue = data->rgb[floor_or_ceiling][2];
	color = create_trgb(0, red, green, blue);
	return (color);
}

int	wall_orientation(t_cub *data)
{
	t_directions	dir;
	int				orientation;

	get_directions_3d(data, &dir);
	if (data->closest_wall == HOR)
	{
		if (dir.up == 1)
			orientation = NO;
		else
			orientation = SO;
	}
	else
	{
		if (dir.right == 1)
			orientation = EA;
		else
			orientation = WE;
	}
	return (orientation);
}

int	get_wall_color(t_cub *data)
{
	int	orientation;

	orientation = wall_orientation(data);
	if (orientation == NO)
		return (ROYAL_BLUE);
	else if (orientation == EA)
		return (BABY_BLUE);
	else if (orientation == SO)
		return (BLUE);
	else
		return (DARK_BLUE);
}
