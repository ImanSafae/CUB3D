/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:36:13 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/21 17:40:23 by abelhadi         ###   ########.fr       */
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
	printf("    |  You have %d seconds to    |.\n", CHRONO_START);
	printf("    |   find it, or you'll be    |.\n");
	printf("    |    locked forever...       |.\n");
	printf("    |                            |.\n");
	printf("    |        GOOD LUCK.          |.\n");
	printf("    |                            |.\n");
	printf("    |   _________________________|___\n");
	printf("    |  /                            /.\n");
	printf("    \\_/____________________________/.\n\n\n");
}

void	name_verifier(char *str)
{
	char	**splited;
	int		i;

	splited = NULL;
	i = 0;
	if (str)
		splited = ft_split(str, '.');
	if (splited == NULL)
		error("failed to verify cub file");
	while (splited && splited[i])
		i++;
	if (ft_strcmp(splited[i - 1], "cub") != 0)
		error("Wrong extension, please peak a cub file");

}

int	main(int argc, char **argv)
{
	t_cub	*c;

	c = NULL;
	if (argc == 2)
	{
		name_verifier(argv[1]);
		srand(time(NULL));
		c = parsing_bonus(argv[1]);
		c->ray = c->angle;
		if (!ft_strncmp(argv[1], "map_tig.cub", ft_strlen("map_tig.cub")))
		{
			print_instructions();
			c->fake_door_mode = true;
			c->time_left = CHRONO_START;
		}
		if (c->paintings_mode == true)
			textures_rng(c);
		draw_3d_bonus(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
