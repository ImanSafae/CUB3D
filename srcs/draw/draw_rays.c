/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:18:30 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/02 13:22:24 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	find_closest_hor_wall(t_cub *data, int x_pixel, int y_pixel, int direction)
{
	/* Cette fonction prend les coordonnées du joueur (en pixels) et la direction dans laquelle il regarde (RIGHT ou LEFT), et retourne la coordonnee du mur 
	le plus proche dans cette direction.
	*/
	int	x_map;
	int	y_map;

	y_map = get_y_coordinate(data, y_pixel);
	x_map = get_x_coordinate(data, x_pixel, y_map);
	if (direction == RIGHT)
	{
		while (x_map < ft_strlen(data->cubmap[y_map]) - 1)
		{
			if (data->cubmap[y_map][x_map] == '1')
				break ;
			x_map++;
		}
	}
	else
	{
		while (x_map >= 0)
		{
			if (data->cubmap[y_map][x_map] == '1')
				break ;
			x_map--;
		}
	}
	return (x_map);
}

int	find_closest_ver_wall(t_cub *data, int x_pixel, int y_pixel, int direction)
{
	/*idem qu'au-dessus mais trouve la coordonnee du mur le plus proche en direction verticale (UP ou DOWN) */
	int	x_map;
	int	y_map;

	y_map = get_y_coordinate(data, y_pixel);
	x_map = get_x_coordinate(data, x_pixel, y_map);
	if (direction == UP)
	{
		while (y_map >= 0)
		{
			if (data->cubmap[y_map][x_map] == '1')
				break ;
			y_map--;
		}
	}
	else
	{
		while (y_map < data->map_height)
		{
			if (data->cubmap[y_map][x_map] == '1')
				break ;
			y_map--;
		}
	}
	return (y_map);
}

int	find_closest_wall(t_cub *data, int direction_ver, int direction_hor)
{
	int	x;
	int	y;
	int	vertical;
	int	horizon;

	x = (int)(data->poz[0]);
	y = (int)(data->poz[1]);
	vertical = find_closest_ver_wall(data, x, y, direction_ver);
	horizon = find_closest_hor_wall(data, x, y, direction_hor);
	if (vertical  < horizon)
		return (vertical);
	else
		return (horizon);
}
