/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:40:25 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/31 15:48:24 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	find_mapstart(char **file)
{
	int	i;
	int	j;

	i = 0;
	//printf("file[%d]: %s\n", i, file[i]);
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

	//printf("======================			get_texture()\n");
	trimed = NULL;
	trimed = ft_strtrim(line, " \t");
	splited = ft_split(trimed, ' ');
	trimed = cub_free(trimed);
	if (splited && splited[0] && ft_strcmp(splited[0], identifier) == 0)
	{
		if (splited[1] && ft_strlen(splited[0]) < 3)
		{
			d->texture_color[index] = ft_strdup(splited[1]);
			splited = free_tab(splited);
		}
		else
		{
			splited = free_tab(splited);
			error("texture file non available: %s");
		}
		return (1);
	}
	return (0);
}

void	copy_textures_tab(t_data *d, t_cub *cub)
{
	d->i = 0;
	cub->textures = NULL;
	cub->textures = malloc(sizeof(char *) * 5);
	if (cub->textures == NULL)
		error("cub->textures malloc failed");
	while (d->texture_color && d->texture_color[d->i] && d->i < 4)
	{
		cub->textures[d->i] = ft_strdup(d->texture_color[d->i]);
		d->i++;
	}
	cub->textures[d->i] = NULL;
}

void	clean_texture(t_cub *cub)
{
	int		ret;
	char	*temp;

	temp = NULL;
	cub->i = 0;
	while (cub->textures && cub->textures[cub->i] && cub->i < 4)
	{
		temp = ft_strtrim(cub->textures[cub->i], "\n");
		ret = open(temp, O_RDONLY, 0);
		temp = cub_free(temp);
		if (ret < 0)
		{		
			error("a texture file is invalid");
		}
		close(ret);
		cub->i++;
	}
}
