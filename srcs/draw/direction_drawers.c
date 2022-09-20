/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_drawers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:49:02 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/20 17:03:39 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	cast()
{
	
}

int	up_right(t_cub *data)
{
	double	ang;
	printf("function ===> UP_RIGHT");
	ang = data->angle;
	if (ang > 0 && ang < PI / 2)
	{
		cast();
	}
	return (0);
}

int	up_left(t_cub *data)
{
	double	ang;

	printf("function ===> UP_LEFT");
	ang = data->angle;
	if (ang > PI / 2 && ang < PI)
	{

	}
	return (0);
}

int	down_right(t_cub *data)
{
	double	ang;
	printf("function ===> DOWN_RIGHT");
	ang = data->angle;
	if (ang > PI && ang < (3 / 2) * PI)
	{

	}
	return (0);
}

int	down_left(t_cub *data)
{
	double	ang;
	printf("function ===> DOWN_LEFT");
	ang = data->angle;
	if (ang > (3 / 2) * PI && ang < PI * 2)
	{

	}
}

int	cardinals(t_cub *data)
{
	double	ang;
	printf("function ===> CARDINALS");
	ang = data->angle;
	if (ang > 0 && ang < PI / 2)
	{

	}
	return (0);
}