/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:48:21 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/02 13:28:42 by itaouil          ###   ########.fr       */
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

int	get_y_coordinate(t_cub *data, int y_pixel)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (i < data->map_height)
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

int	get_x_coordinate(t_cub *data, int x_pixel, int y)
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

void	put_pixel_to_image(t_cub *data, int x, int y, int color)
{
	char	*pixel;
	int		position;
	t_mlx	*m;

	m = data->mlx;
	position = (x * (m->bpix / 8)) + (y * m->line);
	pixel = m->img_addr + (y * m->line + x * (m->bpix / 8));
	*(unsigned int *)pixel = color;
}

void	get_map_param(t_cub *cub)
{
	int	map_len;

	map_len = 0;
	if (cub && cub->cubmap[0])
		map_len = ft_strlen(cub->cubmap[0]) * 64;
	cub->map_len = map_len;
	cub->map_height = cub->map_height * 64;
}

void	init_window(t_cub **data, int length, int height)
{
	t_mlx	*m;

	m = (*data)->mlx;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, length, height, "cub3d");
	m->img_ptr = mlx_new_image(m->mlx_ptr, length, height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix), &(m->line), &(m->end));
}
