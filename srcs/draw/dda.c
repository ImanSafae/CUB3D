/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:10:09 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/24 18:18:27 by itaouil          ###   ########.fr       */
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

static int	dda_number_of_steps(t_point a, t_point b)
{
	double	dx;
	double	dy;
	int		steps;

	dx = (double)(b.x) - (double)(a.x);
	dy = (double)(b.y) - (double)(a.y);
	if (abs_val(dx) > abs_val(dy))
		steps = abs_val((int)dx);
	else
		steps = abs_val((int)dy);
	return (steps);
}

void	dda(t_cub *data, t_point a, t_point b, int color)
{
	double	xinc;
	double	yinc;
	int		steps;
	int		i;

	if (b.x < 0)
		b.x = 0;
	if (b.y < 0)
		b.y = 0;
	i = 1;
	steps = dda_number_of_steps(a, b);
	xinc = ((double)(b.x) - (double)(a.x)) / steps;
	yinc = ((double)(b.y) - (double)(a.y)) / steps;
	while (i <= steps)
	{
		put_pixel_to_image(data, a.x, a.y, color);
		a.x += xinc;
		a.y += yinc;
		i++;
	}
}
