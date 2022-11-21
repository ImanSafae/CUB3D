/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:49:32 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/21 18:41:16 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_release_bonus(int mousecode, int x, int y, t_cub *data)
{
	(void)x;
	(void)y;
	if (mousecode == SCROLL_UP && data->right_arrow == true)
		data->right_arrow = false;
	if (mousecode == SCROLL_DOWN && data->left_arrow == true)
		data->left_arrow = false;
	render_3d_bonus(data);
	return (0);
}

int	mouse_press_bonus(int mousecode, int x, int y, t_cub *data)
{
	(void)x;
	(void)y;
	if (mousecode == SCROLL_UP)
		data->angle -= 0.20;
	else if (mousecode == SCROLL_DOWN)
		data->angle += 0.20;
	render_3d_bonus(data);
	return (0);
}
