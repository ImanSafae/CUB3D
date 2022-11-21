/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:29:54 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/21 18:25:40 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_release_bonus(int keycode, t_cub *data)
{
	if (keycode == RIGHT_ARROW && data->right_arrow == true)
		data->right_arrow = false;
	if (keycode == LEFT_ARROW && data->left_arrow == true)
		data->left_arrow = false;
	if (keycode == W_KEY && data->w_key == true)
		data->w_key = false;
	if (keycode == A_KEY && data->a_key == true)
		data->a_key = false;
	if (keycode == S_KEY && data->s_key == true)
		data->s_key = false;
	if (keycode == D_KEY && data->d_key == true)
		data->d_key = false;
	render_3d_bonus(data);
	return (1);
}

int	key_press_bonus(int keycode, t_cub *data)
{
	if (keycode == ESC)
		end_cub(data);
	if (keycode == SPACE_BAR)
		look_for_door_close(data);
	if (keycode == LEFT_ARROW)
		data->left_arrow = true;
	if (keycode == RIGHT_ARROW)
		data->right_arrow = true;
	if (keycode == W_KEY)
		data->w_key = true;
	if (keycode == A_KEY)
		data->a_key = true;
	if (keycode == S_KEY)
		data->s_key = true;
	if (keycode == D_KEY)
		data->d_key = true;
	render_3d_bonus(data);
	return (1);
}
