/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:18:26 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/31 15:30:17 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// AHC CODE 
/*
int	apply_key(int key, t_cub *cub)
{
	if (key == 69)
		cub->zoom += 3;
	if (key == 78)
		cub->zoom -= 3;
	if (key == 92)
		cub->zoom_z += 1;
	if (key == 88)
		cub->zoom_z -= 1;
	if (key == 1)
		cub->shifty -= 10;
	if (key == 13)
		cub->shifty += 10;
	if (key == 0)
		cub->shiftx -= 10;
	if (key == 2)
		cub->shiftx += 10;
	if (key == 123)
		cub->angle += 0.05;
	if (key == 124)
		cub->angle -= 0.05;
	return (0);
}

int	key_manager(int key, t_cub *c)
{
	if (key == 53)
	{
		free_allcub(c);
		mlx_destroy_window(c->mlx, c->win);
		exit(1);
		return (0);
	}
	apply_key(key, c);
	mlx_clear_window(c->mlx, c->win);
	mlx_destroy_image(c->mlx, c->img);
	c->img = mlx_new_image(&c->mlx, WIDTH, HEIGHT);
	draw_2d(c);
	mlx_put_image_to_window(c->mlx, c->win, c->img, 0, 0);
	text_dislay(c);
	return (0);
}
*/