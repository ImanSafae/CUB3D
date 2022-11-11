/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:33:03 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/11 00:38:39 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_data(t_data *d)
{
	free(d->filename);
	d->i = -1;
	while (d->file && d->file[++d->i])
		free(d->file[d->i]);
	free(d->file);
	d->i = -1;
	while (d->texture_color && d->texture_color[++d->i])
		free(d->texture_color[d->i]);
	free(d->texture_color);
	d->i = -1;
	while (d->map && d->map[++d->i])
		free(d->map[d->i]);
	free(d->map);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab && tab[++i])
		free(tab[i]);
	free(tab);
	tab = NULL;
}

void	end_cub(t_cub *data)
{
	mlx_destroy_window(data->map3d->mlx_ptr, data->map3d->win_ptr);
	free_tab(data->cubmap);
	free(data->player);
	if (data->fake_door_mode == true)
		printf("YOU FOUND THE PORTAL. CONGRATS ON ESCAPING\n");
	exit(EXIT_SUCCESS);
}
