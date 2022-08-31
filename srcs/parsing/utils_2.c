/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:33:03 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/23 11:37:00 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


/*
typedef struct s_data
{
	char	*filename;
	char	**file;
	char	**map;
	char	**texture_color;
	int		map_size;
	int		error_no;
	int		found;
	int		fd;
	int		mid_line;
	int		i;
	int		j;
}	t_data;
*/

void	free_data(t_data *d)
{
	d->filename = cub_free(d->filename);
	d->i = -1;
	while (d->file && d->file[++d->i])
		d->file[d->i] = cub_free(d->file[d->i]);
	free(d->file);
	d->i = -1;
	while (d->texture_color && d->texture_color[++d->i])
		d->texture_color[d->i] = cub_free(d->texture_color[d->i]);
	free(d->texture_color);
	d->i = -1;
	while (d->map && d->map[++d->i])
		d->map[d->i] = cub_free(d->map[d->i]);
	free(d->map);
}

char	**free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		tab[i] = cub_free(tab[i]);
	free(tab);
	tab = NULL;
	return (tab);
}
