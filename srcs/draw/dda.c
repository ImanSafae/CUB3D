/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:10:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/10 16:02:56 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	abs_val(int number)
{
	if (number < 0)
		return (number * -1);
	else
		return (number);
}

void	dda(t_cub *data, t_point *a, t_point *b)
{
	float	dx;
	float	dy;
	int		steps;
	float	xinc;
	float	yinc;
	int		i;

	if (b->x < 0)
		b->x = 0;
	if (b->y < 0)
		b->y = 0;
	dx = (float)(b->x) - (float)(a->x);
	dy = (float)(b->y) - (float)(a->y);
	i = 1;
	if (abs_val(dx) > abs_val(dy))
		steps = abs_val((int)dx);
	else
		steps = abs_val((int)dy);
	xinc = dx / steps;
	yinc = dy / steps;
	printf("dx = %f et dy = %f et xinc = %f et yinc = %f\n", dx, dy, xinc, yinc);
	while (i <= steps)
	{
		// printf("x = %f et y = %f\n", a->x, a->y);
		put_pixel_to_image(data, a->x, a->y, GREEN);
		a->x = a->x + xinc;
		a->y = a->y + yinc;
		i++;
	}
}
