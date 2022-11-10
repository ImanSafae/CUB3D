/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:36:13 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/10 19:08:51 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_instructions(void)
{
	printf("   ______________________________\n");
	printf(" / \\                             \\.\n");
	printf("|   |                            |.\n");
	printf(" \\_ |     In this mode,          |.\n");
	printf("    | walls are made of doors.   |.\n");
	printf("    |     ONE of the doors is    |.\n");
	printf("    |    fake and will free you  |.\n");
	printf("    |      from this maze.       |.\n");
	printf("    |                            |.\n");
	printf("    |  You have 30 seconds to    |.\n");
	printf("    |   find it, or you'll be    |.\n");
	printf("    |    locked forever...       |.\n");
	printf("    |                            |.\n");
	printf("    |        GOOD LUCK.          |.\n");
	printf("    |                            |.\n");
	printf("    |   _________________________|___\n");
	printf("    |  /                            /.\n");
	printf("    \\_/____________________________/.\n");
}

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
	
	srand(time(NULL));
	if (argc == 2)
	{
		
		c = parsing_bonus(argv[1]);
		c->ray = c->angle;
		// while (1)
		// {
		// 	system("leaks cub3d");
		// }
		if (!ft_strncmp(argv[1], "map_tig.cub", ft_strlen("map_tig.cub")))
		{
			print_instructions();
			c->fake_door_mode = true;
		}
		if (c->paintings_mode == true)
			textures_rng(c);
		draw_3d_bonus(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
