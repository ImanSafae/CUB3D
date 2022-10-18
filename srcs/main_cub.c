/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:07:32 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/18 21:05:52 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	init_mlxptr(t_cub *c)
{
	c->mini->mlx_ptr = NULL;
	c->mini->win_ptr = NULL;
	c->mini->img_addr = NULL;
	c->mini->img_ptr = NULL;
	c->mini->bpix = 0;
	c->mini->end = 0;
	c->mini->bpix = 0;
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
	c->angle = (PI) / 2;
	c->ray = c->angle;
	// draw2d(c);
	draw_3d(c);
	// texturing(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
