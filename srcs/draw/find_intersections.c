/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:17:05 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/19 01:20:56 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	get_right_angle(t_cub *data, t_directions *dir, int grid)
{
	float	angle;

	angle = 0;
	if (dir->up == 1 && dir->right == 1 && grid == VERT)
		angle = data->ray;
	if (dir->up == 1 && dir->right == 1 && grid == HOR)
		angle = (PI / 2) - data->ray;
	if (dir->up == 1 && dir->left == 1 && grid == HOR)
	{
		// printf("up left hor\n");
		angle = data->ray - (PI / 2);
	}
	if (dir->up == 1 && dir->left == 1 && grid == VERT)
	{
		// printf("up left vert\n");
		angle = PI - data->ray;
	}
	if (dir->down == 1 && dir->left == 1 && grid == HOR)
	{
		// printf("down left hor\n");
		angle = (3 * PI / 2) - data->ray;
	}
	if (dir->down == 1 && dir->left == 1 && grid == VERT)
	{
		// printf("down left vert\n");
		angle = data->ray - PI;
	}
	if (dir->down == 1 && dir->right == 1 && grid == HOR)
	{
		angle = data->ray - (3 * PI / 2);
		// printf("down right hor\n");
	}
	if (dir->down == 1 && dir->right == 1 && grid == VERT)
	{
		// printf("down right vert\n");
		angle = (2 * PI) - data->ray;
	}
	if (data->ray == PI)
		printf("il y a moktar sous roche\n");
	return (angle);
}

void	check_limits(t_cub *data, t_point *wall)
{
	// printf("checking limits : y = %f\n", wall->y);
	if (wall->x < 0)
		wall->x = 0;
	if (wall->y < 0)
		wall->y = 0;
	if (wall->x > data->map_len)
		wall->x = data->map_len;
	if (wall->y > data->map_height)
		wall->y = data->map_height;
}

int	is_wall(t_cub *data, t_point *point, t_directions *dir)
{
	int	x;
	int	y;

	(void)dir;
	// x = point->x / 64;
	// y = point->y / 64;
	// if (x >= data->map_len / 64)
	// 	x = data->map_len / 64 - 1;
	// if (y >= data->map_height / 64)
	// 	y = data->map_height / 64 - 1;
	// printf("x = %d et len = %d\n", x, data->map_len / 64);
	// printf("y = %d et height = %d\n", y, data->map_height / 64);
	y = get_y_coordinate(data, point->y);
	x = get_x_coordinate(data, point->x, y);
	if (data->cubmap[y][x] == '1')
	{
		// printf("???????????????????????");
		return (1);
	}
	// if (dir->down == 1)
	// {
	// 	if (data->cubmap[y + 1][x] == '1')
	// 	{
	// 		// printf("x = %d et y = %d\n", x, y);
	// 		return (1);
	// 	}
	// }
	// else if (dir->right == 1)
	// {
	// 	if (data->cubmap[y][x + 1] == '1')
	// 	{
	// 		// printf("x = %d et y = %d\n", x, y);
	// 		return (1);
	// 	}
	// }
	return (0);
}

t_point	*first_hor_intersection(t_cub *data, t_directions *dir)
{
	t_point	*intersection;
	float	angle;

	intersection = malloc(sizeof(t_point));
	angle = get_right_angle(data, dir, HOR);
	if (dir->up == 1)
		intersection->y = ((int)(data->poz[1]) / 64) * 64 - 1;
	else
		intersection->y = ((int)(data->poz[1]) / 64) * 64 + 63;
	intersection->x = (int)(data->poz[0]) + (((int)(data->poz[1]) - intersection->y) / tan(angle));
	return (intersection);
}

void	next_hor_intersection(t_cub *data, t_directions *dir, t_point **point)
{
	int		Ya;
	int		Xa;
	float	angle;

	angle = get_right_angle(data, dir, HOR);
	if (dir->up == 1)
		Ya = -64;
	else
		Ya = 64;
	Xa = 64 / tan(angle);
	(*point)->y = (*point)->y + Ya;
	(*point)->x = (*point)->x - Xa;
	check_limits(data, *point);
	
}

t_point	*first_ver_intersection(t_cub *data, t_directions *dir)
{
	t_point	*intersection;
	float	angle;

	angle = get_right_angle(data, dir, VERT);
	intersection = malloc(sizeof(t_point));
	if (dir->right == 1)
		intersection->x = ((int)(data->poz[0]) / 64) * 64 + 63;
	else
		intersection->x = ((int)(data->poz[0]) / 64) * 64 - 1;
	intersection->y = data->poz[Y] + ((data->poz[X]) - intersection->x) / tan(angle);
	// printf("angle = %f\n", data->ray);
	return (intersection);
}

void	next_ver_intersection(t_cub *data, t_directions *dir, t_point **point)
{
	int		Xa;
	int		Ya;
	float	angle;

	angle = get_right_angle(data, dir, VERT);
	if (dir->right == 1)
		Xa = 64;
	else
		Xa = -64;
	Ya = 64 * tan(angle);
	printf("Ya = %d\n", Ya);
	(*point)->x = (*point)->x + Xa;
	(*point)->y = (*point)->y - Ya;
	check_limits(data, *point);
}

t_point	*paint_hor_intersections(t_cub *data, t_directions *dir)
{
	t_point	*intersection;

	intersection = malloc(sizeof(t_point));
	intersection = first_hor_intersection(data, dir);
	// put_pixel_to_image(data, intersection->x, intersection->y, WHITE);
	// printf("hor intersection's x = %f et intersection's y = %f\n", intersection->x, intersection->y);
	// printf("hor: angle = %f, ray = %f\n", data->angle, data->ray);
	if (dir->up == 1)
	{
		// printf("direction = UP\n");
		while (!(is_wall(data, intersection, dir)))
			next_hor_intersection(data, dir, &intersection);
	}
	if (dir->down == 1)
	{
		// printf("direction = DOWN\n");
		while (!(is_wall(data, intersection, dir)))
		{
			next_hor_intersection(data, dir, &intersection);
			// put_pixel_to_image(data, intersection->x, intersection->y, WHITE);
		}
	}
	return (intersection);
}

t_point	*paint_ver_intersections(t_cub *data, t_directions *dir)
{
	t_point	*intersection;

	intersection = first_ver_intersection(data, dir);
	// printf("ver: angle = %f, ray = %f\n", data->angle, data->ray);
	// printf("ver intersection's x = %f et intersection's y = %f\n", intersection->x, intersection->y);
	// if (dir->right == 1)
	// {
		// printf("direction = RIGHT\n");
		while (!(is_wall(data, intersection, dir)))
		{
			// printf("intersection's x = %f et intersection's y = %f\n", intersection->x, intersection->y);
			next_ver_intersection(data, dir, &intersection);
		}
	// }
	// if (dir->left == 1)
	// {
	// 	// printf("direction = LEFT\n");
	// 	while (!(is_wall(data, intersection, dir)))
	// 	{
	// 		next_ver_intersection(data, dir, &intersection);
	// 		// break ;
	// 	}
	// }
	return (intersection);
}

float	get_distance(float ray, t_point *player, t_point *wall)
{
	float	distance;

	distance = abs_val((player->x - wall->x) / (cos(ray)));
	return (abs_val(distance));
}

// int	lateral_direction(t_cub *data)
// {
// 	int	direction;

// 	// printf("angle = %f\n", data->ray);
// 	if ((data->ray >= 0 && data->ray < PI / 2) || (data->ray > 3 * PI / 2 && data->ray <= (2 * PI)))
// 		direction = RIGHT;
// 	// else if (data->ray == PI / 2 || data->ray == 3 * PI / 2)
// 	// 	direction = NONE;
// 	else
// 		direction = LEFT;
// 	return (direction);
// }

// int	forward_direction(t_cub *data)
// {
// 	int	direction;

// 	// printf("angle = %f\n", data->ray);
// 	// if (data->ray == PI || data->ray == 0 || data->ray == 2 * PI)
// 	// 	direction = NONE;
// 	if (data->ray < PI)
// 		direction = UP;
// 	else
// 		direction = DOWN;
// 	return (direction);
// }

void	set_directions(t_cub *data, t_directions *directions)
{
	directions->down = 0;
	directions->up = 0;
	directions->left = 0;
	directions->right = 0;
	if ((data->ray >= 0 && data->ray < PI / 2) || (data->ray > (3 * PI) / 2 && data->ray <= (2 * PI)))
	{
		printf("\n\nriiiiight\n");
		directions->right = 1;
	}
	else
	{
		printf("\n\nON EST DANS LE left LA OU PAS LA \n");
		directions->left = 1;
	}
	if (data->ray < PI)
	{
		printf("ON EST DANS LE UP LA OU PAS LA \n");
		directions->up = 1;
	}
	else
	{
		printf("down down down\n");
		directions->down = 1;
	}
	
}

void	cast_ray(t_cub *data)
{
	(void)double	ver_distance;
	(void)double	hor_distance;
	(void)t_point	*ver_intersection;
	(void)t_point	*hor_intersection;
	(void)t_point	*player;
	(void)t_directions	*dir;

	//player = malloc(sizeof(t_point));
	//player->x = (data->poz[X]);
	//player->y = (data->poz[Y]);
	////dir = malloc(sizeof(t_directions));
	//set_directions(data, dir);
	//hor_intersection = paint_hor_intersections(data, dir);
	//ver_intersection = paint_ver_intersections(data, dir);
	//ver_distance = get_distance(data->ray, player, ver_intersection);
	//hor_distance = get_distance(data->ray, player, hor_intersection);
	//// printf("hor distance = %f amd ver distance = %f\n", hor_distance, ver_distance);
	//// put_pixel_to_image(data, hor_intersection->x, hor_intersection->y, WHITE);
	//// put_pixel_to_image(data, ver_intersection->x, ver_intersection->y, WHITE);
	//// printf("hor intersection->x = %f amd ver intersection->x = %f\n", hor_intersection->x, ver_intersection->x);
	//// printf("hor intersection->y = %f amd ver intersection->y = %f\n", hor_intersection->y, ver_intersection->y);
	//// printf("angle = %f, ray = %f\n", data->angle, data->ray);
	//printf("angle = %f\n", data->ray);
	//if (hor_distance < ver_distance)
	//{
	//	dda(data, player, hor_intersection, RED);
	//	printf("x = %f, y = %f\n", hor_intersection->x, hor_intersection->y);
	//}
	//else
	//{
	//	dda(data, player, ver_intersection, GREEN);
	//	printf("x = %f, y = %f\n", ver_intersection->x, ver_intersection->y);
	//}
	up_right(data);
	up_left(data);
	down_right(data);
	down_left(data);
	cardinals(data);
}

// void	cardinal_rays(t_cub *data)
// {
// 	t_point	*player;
// 	t_point	*wall;

// 	player = malloc(sizeof(t_point));
// 	player->x = (data->poz[0]);
// 	player->y = (data->poz[1]);
// 	if (data->ray == PI / 2)
// 		wall = paint_hor_intersections(data, UP);
// 	else if (data->ray == PI)
// 		wall = paint_ver_intersections(data, LEFT);
// 	else if (data->ray == 3 * PI / 2)
// 		wall = paint_hor_intersections(data, DOWN);
// 	else
// 		wall = paint_ver_intersections(data, RIGHT);
// 	dda(data, player, wall);
// }

void	ray_casting(t_cub *data)
{
	// float	fov_ray;
	// float	incr;
	double	angle_test;
	get_fov(data->angle, START);
	get_fov(data->angle, FINISH);
	// fov_ray = data->angle + 0.52; // ang + 30deg
	// incr = 1.05 / 320; // dist between 2 rays
	// data->ray = fov_ray; // stock ray
	angle_test = 0;
	while (angle_test < PI * 2)
	{
		cast_ray(data);
	}
	// fov_ray = fov_ray - incr;
	// while (fov_ray > data->angle - 0.52) // ang - 30deg
	// {
	// 	data->ray = fov_ray;
	// 	// if (data->ray == PI || data->ray == PI / 2 || data->ray == 0 || data->ray == 3 * PI / 2 || data->ray == 2 * PI)
	// 	// 	cardinal_rays(data);
	// 	// else
	// 		paint_ray(data);
	// 	fov_ray = fov_ray - incr;
	// }
	// data->ray = data->angle - 0.52;
	// paint_ray(data);
	data->ray = data->angle;
}
