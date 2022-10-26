/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   congratulations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:22 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 02:53:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    congratulations_screen(t_cub *data)
{
    mlx_destroy_image(data->map3d->mlx_ptr, data->map3d->img_ptr);
}