/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:07:32 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/11 14:41:06 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

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
		c = parsing(argv[1]);
		c->ray = c->angle;
		draw_3d(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
