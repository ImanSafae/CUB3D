/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:08:32 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/19 00:42:49 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
	
unsigned int	texturing(t_cub *data, double projected_height, double y_wall)
{
	unsigned int	texture_pixel;
	t_img			texture;
	int				orientation;
	int				texture_x;
	int				texture_y;

	orientation = wall_orientation(data);
	texture = data->textures[orientation];
	if (data->closest_wall == HOR)
		texture_x = (int)(data->intersection.x) % WALLS_SIDE;
	else
		texture_x = (int)(data->intersection.y) % WALLS_SIDE;
	texture_y = (int)((y_wall * WALLS_SIDE) / projected_height);
	texture_pixel = *(unsigned int *)(texture.addr + ((int)texture_y * texture.line + (int)texture_x * (texture.bpix / 8)));
	return (texture_pixel);
}
