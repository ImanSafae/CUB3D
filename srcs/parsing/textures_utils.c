/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtur_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
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
	while (c->txtur && c->txtur[c->i] && c->i < 4)
	{
		temp = ft_strtrim(c->txtur[c->i], "\n");
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

	mlx = c->mlx->mlx_ptr;
	i = -1;
	while (c->txtur && c->txtur[++i])
	{
		c->t[i].img = mlx_xpm_file_to_image(mlx, c->txtur[i], c->t[i].width, c->t[i].height);
		printf("texture image created = %p\n", c->t[i].img);
	}
}