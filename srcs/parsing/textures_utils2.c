/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:18:00 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/11 15:25:55 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	check_xpm(char *str)
{
	char	**splited;
	int		i;

	i = 0;
	splited = NULL;
	if (str)
		splited = ft_split(str, '.');
	while (splited && splited[i])
	{
		i++;
	}
	if (i != 2)
		error("error with texture files (check_xpm)");
	if (ft_strcmp(splited[1], "xpm"))
		error("Error with texture file extension");
	free_tab(splited);
	return (0);
}

void	parse_txtur(t_cub *c)
{
	void	*mlx;
	int		i;

	c->textures[NO].img = NULL;
	c->textures[EA].img = NULL;
	c->textures[SO].img = NULL;
	c->textures[WE].img = NULL;
	c->textures[DOOR].img = NULL;
	c->textures[END].img = NULL;
	mlx = mlx_init();
	c->txtr_mlx_ptr = mlx;
	i = -1;
	while (c->txtur && c->txtur[++i] && i < 6)
	{
		c->textures[i].img = mlx_xpm_file_to_image(mlx, c->txtur[i],
				&c->textures[i].width, &c->textures[i].height);
		c->textures[i].addr = mlx_get_data_addr(c->textures[i].img,
				&c->textures[i].bpix, &c->textures[i].line,
				&c->textures[i].endian);
		if (c->textures[i].img == NULL)
			error("xpm_to_image couldn't get texture image");
	}
}
