/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:34:20 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/25 00:18:32 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_character_pos(t_cub *data, int x, int y)
{
	data->player = malloc(sizeof(t_point));
	data->poz[0] = (double)((x * 64) + 31);
	data->poz[1] = (double)((y * 64) + 31);
	data->player->x = data->poz[0];
	data->player->y = data->poz[1];
	data->mini_playr.x = data->player->x / 64 * MINI_RATIO;
	data->mini_playr.y = data->player->y / 64 * MINI_RATIO;
}

void	find_character_in_map(t_cub *data)
{
	int		x_map;
	int		y_map;
	bool	found;

	x_map = 0;
	y_map = 0;
	found = false;
	while (y_map < data->map_height / 64)
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
}
