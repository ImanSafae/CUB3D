/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/19 19:44:06 by itaouil          ###   ########.fr       */
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

void	init_character_pos(t_cub *data, int x, int y)
{
	// renseigne sur la position du joueur lorsque le jeu commence, en pixels (il est donc pour l'instant au centre de son carré)
	data->poz[0] = (float)((x * 64) + 31);
	data->poz[1] = (float)((y * 64) + 31);
}

void	draw_character(t_cub *data, int x, int y)
{
	int	center_x;
	int	center_y;
	int	i;
	int	j;

	center_x = (x * 64) + 32;
	center_y = (y * 64) + 32;
	i = center_x - 5;
	j = center_y - 5;
	while (j <= center_y + 5)
	{
		while (i <= center_x + 5)
		{
			put_pixel_to_image(data, i, j, YELLOW);
			i++;
		}
		i = center_x - 5;
		j++;
	}
}

void	show_character(t_cub *data)
{
	// Cette fonction trouve le perso sur la map et envoie sa position (en unités de map et non en pixels) à la fonction draw_character
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
	draw_character(data, x_map, y_map);
	init_character_pos(data, x_map, y_map);
}

void	paint_wall_or_space(t_cub *data, int x_pixel, int y_pixel)
{
	int	x;
	int	y;

	y = get_y_coordinate(data, y_pixel);
	x = get_x_coordinate(data, x_pixel, y);
	if ((data->cubmap[y][x] == '0') || is_persona(data->cubmap[y][x], OPEN))
		put_pixel_to_image(data, x_pixel, y_pixel, WHITE);
	else
		put_pixel_to_image(data, x_pixel, y_pixel, GREY);
}

void	draw_map(t_cub *cub)
{
	int	i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y < cub->map_height)
	{
		while (i_x < cub->map_len)
		{
			if ((i_x + 1) % 64 == 0 || (i_y + 1) % 64 == 0)
				put_pixel_to_image(cub, i_x, i_y, BLACK);
			else
				paint_wall_or_space(cub, i_x, i_y);
			i_x++;
		}
		i_x = 0;
		i_y++;
	}
}


void	draw2d(t_cub *cub)
{
	t_mlx	*m;

	m = cub->mlx;
	get_map_param(cub);
	init_window(&cub, cub->map_len, cub->map_height);
	draw_map(cub);
	show_character(cub);
	paint_fov(cub);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
	mlx_key_hook(m->win_ptr, rotation_and_moves, cub);
	// printf("closest wall = %d\n", find_closest_hor_wall(cub, (int)(cub->poz[0]), (int)(cub->poz[0]), RIGHT));
	mlx_loop(m->mlx_ptr);
}
