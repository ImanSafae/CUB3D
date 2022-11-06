/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:36:13 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/06 23:38:28 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	init_mlxptr(t_cub *c)
// {
// 	c->mini->mlx_ptr = NULL;
// 	c->mini->win_ptr = NULL;
// 	c->mini->img_addr = NULL;
// 	c->mini->img_ptr = NULL;
// 	c->mini->bpix = 0;
// 	c->mini->end = 0;
// 	c->mini->bpix = 0;
// }

int	main(int argc, char **argv)
{
	t_cub	*c;

	c = NULL;
	if (argc == 2)
	{
		
		c = parsing_bonus(argv[1]);
		textures_rng(c);
		c->ray = c->angle;
		// while (1)
		// {
		// 	system("leaks cub3d");
		// }
		draw_3d_bonus(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
