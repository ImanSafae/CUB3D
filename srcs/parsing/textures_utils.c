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
	trimed = ft_strtrim(line, " \t");
	splited = ft_split(trimed, ' ');
	free(trimed);
	if (splited && splited[0] && ft_strcmp(splited[0], identifier) == 0)
	{
		if (splited[1] && ft_strlen(splited[0]) < 3)
		{
			d->texture_color[index] = ft_strdup(splited[1]);
			free_tab(splited);
		}
		else
		{
			free_tab(splited);
			error("texture file non available: %s");
		}
		return (1);
	}
	free_tab(splited);
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
	int		stop;

	temp = NULL;
	c->i = 0;
	if (c->paintings_mode == true)
		stop = 16;
	else
		stop = 6;
	while (c->txtur && c->txtur[c->i] && c->i < stop)
	{
		if (stop == 16 && c->i == 6)
			c->i = 8;
		temp = ft_strtrim(c->txtur[c->i], "\n");
		free(c->txtur[c->i]);
		c->txtur[c->i] = ft_strdup(temp);
		check_xpm(temp);
		ret = open(temp, O_RDONLY, 0);
		free(temp);
		if (ret < 0)
			error("a texture file is not opening");
		close(ret);
		c->i++;
	}
}
