/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:16:08 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 17:08:50 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_for_random_txtr(t_cub *data, int x_map, int y_map)
{
	if (data->cubmap[y_map][x_map] == 'P')
		return (RANDOM1);
	else if (data->cubmap[y_map][x_map] == 'Q')
		return (RANDOM2);
	else if (data->cubmap[y_map][x_map] == 'R')
		return (RANDOM3);
	else if (data->cubmap[y_map][x_map] == 'Y')
		return (RANDOM4);
	else if (data->cubmap[y_map][x_map] == 'T')
		return (RANDOM5);
	else if (data->cubmap[y_map][x_map] == 'U')
		return (RANDOM6);
	else if (data->cubmap[y_map][x_map] == 'V')
		return (RANDOM7);
	else if (data->cubmap[y_map][x_map] == 'X')
		return (RANDOM8);
	else
		return (0);
}

int	check_for_door_or_special_txtr(t_cub *data)
{
	int	x_map;
	int	y_map;

	x_map = data->intersection.x / WALLS_SIDE;
	y_map = data->intersection.y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'D')
		return (DOOR);
	else if (data->cubmap[y_map][x_map] == 'Z')
		return (END);
	else
		return (check_for_random_txtr(data, x_map, y_map));
}
