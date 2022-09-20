/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:05:37 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/08 15:06:01 by abelhadi         ###   ########.fr       */
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
