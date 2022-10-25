/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:29:54 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/25 03:41:51 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	closest_wall_is_door(t_cub *data)
{
	int	x_map;
	int	y_map;

	x_map = data->intersection.x / WALLS_SIDE;
	y_map = data->intersection.y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'D' || data->cubmap[y_map][x_map] == 'O')
	{
		// printf("close to door");
		return (1);
	}
	return (0);
}

void	open_or_close_door(t_cub *data)
{
	int	x_map;
	int	y_map;

	printf("close to door");
	x_map = data->intersection.x / WALLS_SIDE;
	y_map = data->intersection.y / WALLS_SIDE;
	if (data->cubmap[y_map][x_map] == 'D')
		data->cubmap[y_map][x_map] = 'O';
	else if (data->cubmap[y_map][x_map] == 'O')
	{
		data->cubmap[y_map][x_map] = 'D';
	}
}

void	look_for_door_close(t_cub *data)
{
	if (!closest_wall_is_door(data))
		return ;
	else if (data->dist_to_closest_wall <= DIST_TO_OPEN_DOORS)
	{
		// printf("close to door");
		open_or_close_door(data);
	}
}

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
