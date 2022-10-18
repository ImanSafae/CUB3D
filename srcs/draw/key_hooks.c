/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:03:44 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/19 00:57:12 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_collisions(t_cub *data, double x, double y)
{
	int	map_x;
	int	map_y;
	// t_directions	dir;

	// dir = get_directions_3d(data, &dir);
	// map_y = get_y_coordinate(data, y);
	// map_x = get_x_coordinate(data, x, map_y);
	map_y = y / WALLS_SIDE;
	map_x = x / WALLS_SIDE;
	// if ((((int)(x) + 1) % 64 != 0) && (((int)(y) + 1) % 64 != 0))
	// 	return (0);
	// if (((int)(x) + 1) % 64 == 0)
	// {
		// if (dir->right == 1)
		// 	map_x++;
		if (data->cubmap[map_y][map_x] == '1')
			return (1);
	// }
	// if (((int)(y) + 1) % 64 == 0)
	// {
		// if (dir->down == 1)
		// 	map_y++;
		if (data->cubmap[map_y][map_x] == '1')
			return (1);
	// }
	return (0);
}

// int	check_collisions(t_cub *data, double x, double y, int direction)
// {
// 	int	map_x;
// 	int	map_y;
	
// 	map_y = get_y_coordinate(data, y);
// 	map_x = get_x_coordinate(data, x, map_y);
// 	if ((((int)(x) + 1) % 64 != 0) && (((int)(y) + 1) % 64 != 0))
// 		return (0);
// 	if (((int)(x) + 1) % 64 == 0)
// 	{
// 		if (direction == RIGHT)
// 			map_x++;
// 		if (data->cubmap[map_y][map_x] == '1')
// 			return (1);
// 	}
// 	if (((int)(y) + 1) % 64 == 0)
// 	{
// 		if (direction == DOWN)
// 			map_y++;
// 		if (data->cubmap[map_y][map_x] == '1')
// 			return (1);
// 	}
// 	return (0);
// }

void	rotation(t_cub *data)
{
	if (data->left_arrow == true)
		data->angle += 0.05;
	else if (data->right_arrow)
		data->angle -= 0.05;
}

// void	lateral_moves(int keycode, t_cub *data, t_directions *dir)
// {
// 	if (keycode == D_KEY)
// 	{
// 		if (!check_collisions(data, data->player->x + 6, data->player->y, RIGHT))
// 		{
// 			data->player->y -= sin(data->ray - (PI / 2)) * SPEED;
// 			data->player->x += cos(data->ray - (PI / 2)) * SPEED;
// 		}
// 	}
// 	if (keycode == A_KEY)
// 	{
// 		if (!check_collisions(data, data->player->x - 6, data->player->y, LEFT))
// 		{
// 			data->player->y -= sin(data->ray + (PI / 2)) * SPEED;
// 			data->player->x += cos(data->ray + (PI / 2)) * SPEED;
// 		}
// 	}
// }

// void	forward_moves(int keycode, t_cub *data, t_directions *dir)
// {
// 	if (keycode == W_KEY)
// 	{
// 		if (!check_collisions(data, data->player->x, data->player->y - 6, UP))
// 		{
// 			data->player->y -= sin(data->ray) * SPEED;
// 			data->player->x += cos(data->ray) * SPEED;
// 		}
// 	}
// 	if (keycode == S_KEY)
// 	{
// 		if (!check_collisions(data, data->player->x, data->player->y + 6, DOWN))
// 		{
// 			data->player->y += sin(data->ray) * SPEED;
// 			data->player->x -= cos(data->ray) * SPEED;
// 		}
// 	}
// }

void	lateral_moves(t_cub *data)
{
	double	new_x;
	double	new_y;

	if (data->d_key == true)
	{
		new_x = data->player->x + cos(data->ray - (PI / 2)) * SPEED;
		new_y = data->player->y - sin(data->ray - (PI / 2)) * SPEED;
		if (!check_collisions(data, new_x, new_y))
		{
			data->player->y = new_y;
			data->player->x = new_x;
		}
	}
	if (data->a_key == true)
	{
		new_y = data->player->y - sin(data->ray + (PI / 2)) * SPEED;
		new_x = data->player->x + cos(data->ray + (PI / 2)) * SPEED;
		if (!check_collisions(data, new_x, new_y))
		{
			data->player->y = new_y;
			data->player->x = new_x;
		}
	}
}

void	forward_moves(t_cub *data)
{
	double	new_x;
	double	new_y;

	if (data->w_key == true)
	{
		new_x = data->player->x + cos(data->ray) * SPEED;
		new_y = data->player->y - sin(data->ray) * SPEED;
		if (!check_collisions(data, new_x, new_y))
		{
			data->player->y = new_y;
			data->player->x = new_x;
		}
	}
	if (data->s_key == true)
	{
		new_y = data->player->y + sin(data->ray) * SPEED;
		new_x = data->player->x - cos(data->ray) * SPEED;
		if (!check_collisions(data, new_x, new_y))
		{
			data->player->y = new_y;
			data->player->x = new_x;
		}
	}
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
	// draw_map(data);
	// draw_character(data);
	// paint_fov(data);
	// mlx_put_image_to_window(data->mini->mlx_ptr, data->mini->win_ptr, data->mini->img_ptr, 0, 0);
	// render_3d(data);
	return (0);
}