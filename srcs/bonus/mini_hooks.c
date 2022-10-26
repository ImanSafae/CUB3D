/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:50:48 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 01:52:02 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mini_collisions(t_cub *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_y = y / MINI_RATIO;
	map_x = x / MINI_RATIO;
	if (data->cubmap[map_y][map_x] == '1' || data->cubmap[map_y][map_x] == 'D'
		|| data->cubmap[map_y][map_x] == 'R')
		return (1);
	return (0);
}

static void	lateral_moves_mini(t_cub *data)
{
	double	new_x;
	double	new_y;

	if (data->d_key == true)
	{
		new_x = data->mini_playr.x + cos(data->ray - (PI / 2)) * SPEED;
		new_y = data->mini_playr.y - sin(data->ray - (PI / 2)) * SPEED;
		if (!mini_collisions(data, new_x, new_y))
		{
			data->mini_playr.y = new_y;
			data->mini_playr.x = new_x;
		}
	}
	if (data->a_key == true)
	{
		new_y = data->mini_playr.y - sin(data->ray + (PI / 2)) * SPEED;
		new_x = data->mini_playr.x + cos(data->ray + (PI / 2)) * SPEED;
		if (!mini_collisions(data, new_x, new_y))
		{
			data->mini_playr.y = new_y;
			data->mini_playr.x = new_x;
		}
	}
}

static void	forward_moves_mini(t_cub *data)
{
	double	new_x;
	double	new_y;

	if (data->w_key == true)
	{
		new_x = data->mini_playr.x + cos(data->ray) * SPEED;
		new_y = data->mini_playr.y - sin(data->ray) * SPEED;
		if (!mini_collisions(data, new_x, new_y))
		{
			data->mini_playr.y = new_y;
			data->mini_playr.x = new_x;
		}
	}
	if (data->s_key == true)
	{
		new_y = data->mini_playr.y + sin(data->ray) * SPEED;
		new_x = data->mini_playr.x - cos(data->ray) * SPEED;
		if (!mini_collisions(data, new_x, new_y))
		{
			data->mini_playr.y = new_y;
			data->mini_playr.x = new_x;
		}
	}
}


int	bonus_moves(t_cub *data)
{
    rotation(data);
	lateral_moves_mini(data);
	forward_moves_mini(data);
	lateral_moves(data);
	forward_moves(data);
	return (0);
}
