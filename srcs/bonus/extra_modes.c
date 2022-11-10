/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:22 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/10 02:37:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    parse_painting_txtur(t_cub *c)
{
    void	*mlx;
	int		i;

    i = 0;
    while (i < 8)
	{
	    c->painting_textures[i].img = NULL;
		i++;
	}
	mlx = mlx_init();
	i = 7;
	while (c->txtur && c->txtur[++i] && i < 16)
	{
		c->painting_textures[i - 8].img = mlx_xpm_file_to_image(mlx, c->txtur[i],
				&c->painting_textures[i - 8].width, &c->painting_textures[i - 8].height);
		c->painting_textures[i - 8].addr = mlx_get_data_addr(c->painting_textures[i - 8].img,
				&c->painting_textures[i - 8].bpix, &c->painting_textures[i - 8].line,
				&c->painting_textures[i - 8].endian);
		if (c->painting_textures[i - 8].img == NULL)
			error("xpm_to_image couldn't get texture image");
	}
	c->txtur = free_tab(c->txtur);
}

char	assign_painting(int rand)
{
	if (rand == 0)
		return ('P');
	else if (rand == 1)
		return ('Q');
	else if (rand == 2)
		return ('R');
	else if (rand == 3)
		return ('S');
	else if (rand == 4)
		return ('T');
	else if (rand == 5)
		return ('U');
	else if (rand == 6)
		return ('V');
	else
		return ('X');
}

void	textures_rng(t_cub *data)
{
	int	i;
	int	j;
	int	rand_painting_or_not;
	int	which_painting;

	i = 0;
	j = 0;
	which_painting = 0;
	while (data->cubmap && data->cubmap[i])
	{
		while (data->cubmap[i][j])
		{
			rand_painting_or_not = rand() % 14;
			if (rand_painting_or_not == 0 && data->cubmap[i][j] == '1')
			{
				which_painting = rand() % 8;
				data->cubmap[i][j] = assign_painting(which_painting);
			}
			j++;
		}
		i++;
		j = 0;
		
	}
}