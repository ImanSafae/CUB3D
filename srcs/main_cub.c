/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:07:32 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/02 16:52:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	init_mlxptr(t_cub *c)
{
	c->mlx->mlx_ptr = NULL;
	c->mlx->win_ptr = NULL;
	c->mlx->img_addr = NULL;
	c->mlx->img_ptr = NULL;
	c->mlx->bpix = 0;
	c->mlx->end = 0;
	c->mlx->bpix = 0;
}

int	main(int argc, char **argv)
{
	t_cub	*c;

	c = NULL;
	if (argc == 2)
	{
		
		c = parsing(argv[1]);
/*
		init_mlxptr(c);
		c->mlx = mlx_init();
		c->win = mlx_new_window(c->mlx, WIDTH, HEIGHT, "CUB3D");
		c->img = mlx_new_image(c->mlx, WIDTH, HEIGHT);
		c->add = mlx_get_data_addr(c->img, &c->bpix, &c->line, &c->end);
		draw_2d(c);
		mlx_put_image_to_window(c->mlx, c->win, c->img, 300, 0);
		text_dislay(c);
		mlx_key_hook(c->win, key_manager, c);
		mlx_loop(c->mlx);
*/
	draw2d(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
