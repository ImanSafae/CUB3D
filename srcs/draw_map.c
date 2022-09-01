/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 16:05:01 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_cub **data, int length, int height)
{
	t_mlx	*m;

	m = (*data)->mlx;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, length, height, "cub3d");
	m->img_ptr = mlx_new_image(m->mlx_ptr, length, height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix), &(m->line), &(m->end));
	printf("bpx = %d\n", m->bpix);
	printf("line = %d\n", m->line);
}

void	paint_wall_or_space(t_cub *data, int x_pixel, int y_pixel)
{
	int	i;
	int	x;
	int	y;

	i = 1;
	x = 0;
	y = 0;
	while (i < data->map_len)
	{
		if ((x_pixel + 1 <= (64 * i)) && (x_pixel + 1 >= (64 * (i - 1))))
		{
			x = i - 1;
			break ;
		}
		i++;
	}
	i = 1;
	while (i < data->map_height)
	{
		if ((y_pixel + 1 <= 64 * i) && (y_pixel + 1 >= 64 * (i - 1)))
		{
			y = i - 1;
			break ;
		}
		i++;
	}
	if (data->cubmap[y][x] == '1')
		put_pixel_to_image(data, x_pixel, y_pixel, GREY);
	else
		put_pixel_to_image(data, x_pixel, y_pixel, WHITE);
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

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
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
}

void	draw2d(t_cub *cub)
{
	t_mlx	*m;

	m = cub->mlx;
	get_map_param(cub);
	// printf("len = %d et height = %d\n", cub->map_len, cub->map_height);
	// init_window(&cub, cub->map_len, cub->map_height);
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, cub->map_len, cub->map_height, "cub3d");
	m->img_ptr = mlx_new_image(m->mlx_ptr, cub->map_len, cub->map_height);
	m->img_addr = mlx_get_data_addr(m->img_ptr, &(m->bpix), &(m->line), &(m->end));
	draw_map(cub);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
	mlx_loop(m->mlx_ptr);
}
