/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:48:21 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/24 16:28:44 by itaouil          ###   ########.fr       */
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

int	get_y_coordinate(t_cub *data, float y_pixel)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	
	while (i < data->map_height / 64)
	{
		if ((y_pixel + 1 <= 64 * i) && (y_pixel + 1 >= 64 * (i - 1)))
		{
			y = (i - 1);
			break ;
		}
		i++;
	}
	return (y);
}

int	get_x_coordinate(t_cub *data, float x_pixel, int y)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i <= ft_strlen(data->cubmap[y]))
	{
		if ((x_pixel + 1 <= 64 * i) && (x_pixel + 1 >= 64 * (i - 1)))
		{
			x = (i - 1);
			break ;
		}
		i++;
	}
	return (x);
}

void	put_pixel_to_image(t_cub *data, float x, float y, int color)
{
	char	*pixel;
	int		position;
	t_mlx	*m;

	m = data->mini;
	position = ((int)x * (m->bpix / 8)) + ((int)y * m->line);
	pixel = m->img_addr + ((int)y * m->line + (int)x * (m->bpix / 8));
	*(unsigned int *)pixel = color;
}

void	get_map_param(t_cub *cub)
{
	// ils sont initialisés dans cub_init() et clean_map() dans la partie parsing().
	cub->map_len *= 64;
	cub->map_height *= 64;
}

void	init_window(t_cub **data, int length, int height)
{
	t_mlx	*m;

	m = (*data)->mini;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, length, height, "cub3d");
	m->img_ptr = mlx_new_image(m->mlx_ptr, length, height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix), &(m->line), &(m->end));
}
