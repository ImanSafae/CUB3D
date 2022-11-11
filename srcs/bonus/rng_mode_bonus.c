/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng_mode_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:44:39 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 18:01:46 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	assign_painting(int rand)
{
	if (rand == 0)
		return ('P');
	else if (rand == 1)
		return ('Q');
	else if (rand == 2)
		return ('R');
	else if (rand == 3)
		return ('Y');
	else if (rand == 4)
		return ('T');
	else if (rand == 5)
		return ('U');
	else
		return ('V');
}

void	textures_rng(t_cub *data)
{
	int	i;
	int	j;
	int	randint;
	int	rand_painting_or_not;
	int	which_painting;

	i = 0;
	j = 0;
	which_painting = 0;
	while (data->cubmap && data->cubmap[i])
	{
		while (data->cubmap[i][j])
		{
			randint = rand();
			rand_painting_or_not = randint % 14;
			if (rand_painting_or_not == 0 && data->cubmap[i][j] == '1')
			{
				which_painting = rand() % 7;
				data->cubmap[i][j] = assign_painting(which_painting);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	turn_peach_into_bowser(t_cub *data)
{
	int		x_map;
	int		y_map;

	x_map = data->intersection.x / WALLS_SIDE;
	y_map = data->intersection.y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'V')
	{
		if (data->dist_to_closest_wall < DIST_TO_TRANSFORM_PEACH)
			data->cubmap[y_map][x_map] = 'X';
	}
	else if (data->cubmap[y_map][x_map] == 'X')
	{
		if (data->dist_to_closest_wall >= DIST_TO_TRANSFORM_PEACH)
			data->cubmap[y_map][x_map] = 'V';
	}
}
