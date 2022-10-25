/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:33:03 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/25 02:31:37 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	end_cub(t_cub *data)
{
	mlx_destroy_window(data->map3d->mlx_ptr, data->map3d->win_ptr);
	free_tab(data->cubmap);
	free_tab(data->txtur);
	free(data->player);
	exit(EXIT_SUCCESS);
}
