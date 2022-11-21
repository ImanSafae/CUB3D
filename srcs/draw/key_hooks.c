/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:03:44 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/21 18:27:10 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	red_cross(int mousecode, t_cub *data)
{
	(void)mousecode;
	(void)data;
	exit(0);
	return (0);
}

int	key_release(int keycode, t_cub *data)
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
	render_3d(data);
	return (1);
}

int	key_press(int keycode, t_cub *data)
{
	if (keycode == ESC || keycode == RED_CROSS)
		end_cub(data);
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
	render_3d(data);
	return (1);
}

int	rotation_and_moves(t_cub *data)
{
	rotation(data);
	lateral_moves(data);
	forward_moves(data);
	return (0);
}
