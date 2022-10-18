/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:47:35 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/04 20:20:34 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_pov(int mousecode, int x, int y, t_cub *data)
{
	int		center;
	double	dx;
	double	new_angle;

	dx = 0.0;
	new_angle = 0.0;
	center = (WIDTH_3D / 2) - 1; // centre de l'image (- 1 car ça commence à 0)
	if (x > center)
	{
		dx = x - center;
		
	}
}