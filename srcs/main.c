/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:07:32 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/21 18:44:54 by itaouil          ###   ########.fr       */
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
		c = parsing(argv[1]);
		c->ray = c->angle;
		draw_3d(c);
	}
	else
		error("Wrong number of arguments");
	return (0);
}
