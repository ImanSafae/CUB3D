/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:10:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/09/07 17:05:03 by itaouil          ###   ########.fr       */
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

	// printf("intersection's x = %f et intersection's y = %f\n", (float)b->x, (float)b->y);
	if (b->x < 0)
		b->x = 0;
	if (b->y < 0)
		b->y = 0;
	dx = (float)(b->x) - (float)(a->x);
	dy = (float)(b->y) - (float)(a->y);
	i = 1;
	if (abs_val(dx) > abs_val(dy))
		steps = abs_val(dx);
	else
		steps = abs_val(dy);
	xinc = dx / steps;
	yinc = dy / steps;
	// printf("dx = %f et dy = %f et xinc = %f et yinc = %f\n", dx, dy, xinc, yinc);
	while (i <= steps)
	{
		put_pixel_to_image(data, a->x, a->y, BLACK);
		a->x = a->x + xinc;
		a->y = a->y + yinc;
		i++;
	}
}
