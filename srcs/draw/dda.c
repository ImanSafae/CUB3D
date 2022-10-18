/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:10:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/11 00:36:06 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	abs_val(double number)
{
	if (number < 0)
		return (number * -1);
	else
		return (number);
}

void	dda(t_cub *data, t_point a, t_point b, int color)
{
	double	dx;
	double	dy;
	int		steps;
	double	xinc;
	double	yinc;
	int		i;

	if (b.x < 0)
		b.x = 0;
	if (b.y < 0)
		b.y = 0;
	dx = (double)(b.x) - (double)(a.x);
	dy = (double)(b.y) - (double)(a.y);
	i = 1;
	if (abs_val(dx) > abs_val(dy))
		steps = abs_val((int)dx);
	else
		steps = abs_val((int)dy);
	xinc = dx / steps;
	yinc = dy / steps;
	// printf("dx = %f et dy = %f et xinc = %f et yinc = %f\n", dx, dy, xinc, yinc);
	while (i <= steps)
	{
		// printf("x = %f et y = %f\n", a.x, a.y);
		put_pixel_to_image(data, a.x, a.y, color);
		a.x = a.x + xinc;
		a.y = a.y + yinc;
		i++;
	}
}
