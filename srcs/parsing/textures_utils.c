/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtur_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:40:25 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 16:53:28 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	find_mapstart(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file && file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (is_map_or_error(file[i][j]))
			return (i);
		i++;
	}
	return (i);
}

int	get_texture(t_data *d, char *line, char *identifier, int index)
{
	char	*trimed;
	char	**splited;

	trimed = NULL;
	trimed = ft_strtrim(line, " \t"); // FREE TRIMED
	splited = ft_split(trimed, ' '); // FREE SPLITED
	trimed = cub_free(trimed);
	if (splited && splited[0] && ft_strcmp(splited[0], identifier) == 0)
	{
		if (splited[1] && ft_strlen(splited[0]) < 3)
		{
			d->texture_color[index] = ft_strdup(splited[1]); // FREE DATA TEXTURE COLOR
			splited = free_tab(splited);
		}
		else
		{
			splited = free_tab(splited);
			error("texture file non available: %s");
		}
		return (1);
	}
	splited = free_tab(splited);
	return (0);
}

void	copy_textures_tab(t_data *d, t_cub *c)
{
	d->i = 0;
	c->txtur = NULL;
	c->txtur = malloc(sizeof(char *) * 5);
	if (c->txtur == NULL)
		error("c->txtur malloc failed");
	while (d->texture_color && d->texture_color[d->i] && d->i < 4)
	{
		c->txtur[d->i] = ft_strdup(d->texture_color[d->i]);
		d->i++;
	}
	c->txtur[d->i] = NULL;
}

void	clean_texture(t_cub *c)
{
	int		ret;
	char	*temp;

	temp = NULL;
	c->i = 0;
	while (c->txtur && c->txtur[c->i] && c->i < 7)
	{
		temp = ft_strtrim(c->txtur[c->i], "\n");
		c->txtur[c->i] = cub_free(c->txtur[c->i]);
		c->txtur[c->i] = ft_strdup(temp);
		check_xpm(temp);
		ret = open(temp, O_RDONLY, 0);
		temp = cub_free(temp);
		if (ret < 0)
		{		
			error("a texture file is not opening");
		}
		close(ret);
		c->i++;
	}
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
	c->textures[RANDOM].img = NULL;
	c->textures[END].img = NULL;
	mlx = mlx_init();
	i = -1;
	while (c->txtur && c->txtur[++i])
	{
		c->textures[i].img = mlx_xpm_file_to_image(mlx, c->txtur[i],
				&c->textures[i].width, &c->textures[i].height);
		c->textures[i].addr = mlx_get_data_addr(c->textures[i].img,
				&c->textures[i].bpix, &c->textures[i].line,
				&c->textures[i].endian);
		if (c->textures[i].img == NULL)
			error("xpm_to_image couldn't get texture image");
	}
	c->txtur = free_tab(c->txtur);
}
