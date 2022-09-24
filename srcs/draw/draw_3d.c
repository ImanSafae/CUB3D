/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:53:14 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/24 16:31:24 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_map(t_cub *data)
{
	t_mlx	*map3d;

	map3d = data->map3d;
	map3d->mlx_ptr = mlx_init();
	map3d->win_ptr = mlx_new_window()
}

void	draw_3d(t_cub *data)
{
	t_mlx	*map3d;

	map3d = malloc(sizeof(t_mlx));
	data->map3d = map3d;
}
