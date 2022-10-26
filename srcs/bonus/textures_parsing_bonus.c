/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parsing_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:29:43 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 02:43:31 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	get_color_bonus(t_data *d, t_cub *cub)
{
	verify_color(d, cub, 7, FLOOR);
	verify_color(d, cub, 8, CEILING);
}

void	copy_textures_tab_bonus(t_data *d, t_cub *c)
{
	d->i = 0;
	c->txtur = NULL;
	c->txtur = malloc(sizeof(char *) * 8);
	if (c->txtur == NULL)
		error("c->txtur malloc failed");
	while (d->texture_color && d->texture_color[d->i] && d->i < 7)
	{
		c->txtur[d->i] = ft_strdup(d->texture_color[d->i]);
		d->i++;
	}
	c->txtur[d->i] = NULL;
}

void	get_texture_color_bonus(t_data *d)
{
	char	**directions;

	d->mid_line = find_mapstart_bonus(d->file);
	directions = (char *[]){"NO", "EA", "SO", "WE", "D", "R", "G", "F", "C", NULL};
	d->j = -1;
	while (directions[++d->j])
	{
		d->i = 0;
		d->found = 0;
		while (d->i < d->mid_line)
		{
			if (get_texture(d, d->file[d->i], directions[d->j], d->j))
				d->found++;
			d->i++;
		}
		if (d->found > 1 || !d->found)
			error("repeated or missing texture, delete/add one and restart");
	}
}
