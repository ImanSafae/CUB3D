/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:01 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/10 23:41:29 by itaouil          ###   ########.fr       */
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
