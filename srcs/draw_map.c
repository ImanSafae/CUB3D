/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 19:37:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	init_window(t_cub **data, int length, int height)
{
	t_mlx	*m;

	m = (*data)->mlx;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, length, height, "cub3d");
	m->img_ptr = mlx_new_image(m->mlx_ptr, length, height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix), &(m->line), &(m->end));
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
	while (i < ft_strlen(data->cubmap[y]))
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

void	paint_character(t_cub *data)
{
	int	x;
	int	y;
	bool	found;

	x = 0;
	y = 0;
	found = false;
	while (y < data->map_height / 64)
	{
		while (x < ft_strlen(data->cubmap[y]))
		{
			if (is_persona(data->cubmap[y][x], OPEN))
			{
				found = true;
				break ;
			}
			x++;
		}
		if (found == true)
			break ;
		x = 0;
		y++;
	}
	draw_character(data, x, y);
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
	paint_character(cub);
}

void	draw2d(t_cub *cub)
{
	t_mlx	*m;

	m = cub->mlx;
	get_map_param(cub);
	init_window(&cub, cub->map_len, cub->map_height);
	draw_map(cub);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
	mlx_loop(m->mlx_ptr);
}
