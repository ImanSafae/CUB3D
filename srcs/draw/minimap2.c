/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:01 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/11 19:37:44 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	init_character_pos(t_cub *data, int x, int y)
{
	data->player = malloc(sizeof(t_point));
	// renseigne sur la position du joueur lorsque le jeu commence, en pixels (il est donc pour l'instant au centre de son carré)
	data->poz[0] = (double)((x * 64) + 31);
	data->poz[1] = (double)((y * 64) + 31);
	data->player->x = data->poz[0];
	data->player->y = data->poz[1];
}

void	init_character(t_cub *data)
{
	// Cette fonction trouve le perso sur la map et envoie sa position (en unités de map et non en pixels) à la fonction init_character_pos
	int		x_map;
	int		y_map;
	bool	found;

	x_map = 0;
	y_map = 0;
	found = false;
	while (y_map < data->map_height / 64)
	{
		while (x_map < ft_strlen(data->cubmap[y_map]))
		{
			if (is_persona(data->cubmap[y_map][x_map], OPEN))
			{
				found = true;
				break ;
			}
			x_map++;
		}
		if (found == true)
			break ;
		x_map = 0;
		y_map++;
	}
	init_character_pos(data, x_map, y_map);
}

void	paint_ray(t_cub *data)
{
	t_directions	*dir;
	double			hor_distance;
	double			ver_distance;
	t_point			*hor_intersection;
	t_point			*ver_intersection;

	dir  = get_directions(data);
	hor_intersection = check_hor_intersections(data, data->player, dir);
	hor_distance = get_distance(data->player, hor_intersection);
	ver_intersection = check_ver_intersections(data, data->player, dir);
	ver_distance = get_distance(data->player, ver_intersection);
	if (ver_distance < hor_distance)
		dda(data, *data->player, *ver_intersection, RED);
	else
		dda(data, *data->player, *hor_intersection, GREEN);
	free(dir);
	free(hor_intersection);
	free(ver_intersection);


	// t_point			*hor_intersection;
	// t_point			*ver_intersection;
	// t_directions	*dir;
	// float			hor_distance;
	// float			ver_distance;

	// dir  = get_directions(data);
	// printf("player->x = %f, player->y = %f\n", data->player->x, data->player->y);
	// hor_intersection = check_hor_intersections(data, data->player, dir);
	// hor_distance = get_distance(data->player, hor_intersection);
	// ver_intersection = check_ver_intersections(data, data->player, dir);
	// ver_distance = get_distance(data->player, ver_intersection);
	// if (ver_distance < hor_distance)
	// 	dda(data, *data->player, *ver_intersection, GREEN);
	// else
	// 	dda(data, *data->player, *hor_intersection, RED);
}

void	paint_fov(t_cub *data)
{
	double	fov_ray;
	double	incr;

	modulo_two_pi(&data->angle);
	fov_ray = data->angle + 0.52; // ang + 30deg
	incr = 1.05 / 320; // dist between 2 rays
	data->ray = fov_ray; // stock ray
	modulo_two_pi(&data->ray);
	paint_ray(data);
	fov_ray = fov_ray - incr;
	while (fov_ray > data->angle - 0.52) // ang - 30deg
	{
		data->ray = fov_ray;
		modulo_two_pi(&data->ray);
		// if (data->ray == PI || data->ray == PI / 2 || data->ray == 0 || data->ray == 3 * PI / 2 || data->ray == 2 * PI)
			// cardinal_rays(data);
		// else
		paint_ray(data);
		fov_ray = fov_ray - incr;
	}
	data->ray = data->angle - 0.52;
	modulo_two_pi(&data->ray);
	paint_ray(data);
	data->ray = data->angle;
}

t_directions	*get_directions(t_cub *data)
{
	t_directions	*dir;

	dir = malloc(sizeof(t_directions));
	dir->down = 0;
	dir->up = 0;
	dir->left = 0;
	dir->right = 0;
	// if (data->ray == 0 || data->ray == PI || data->ray == PI / 2 || data->ray == 3 * PI / 2)
	// {
	// 	//cette condition ne devrait jamais etre checkée
	// 	printf("can't do this angle yet\n");
	// 	exit(EXIT_FAILURE);
	// }
	if (data->ray > 0 && data->ray < PI)
		dir->up = 1;
	else
		dir->down = 1;
	if ((data->ray > 0 && data->ray < PI / 2) || (data->ray > 3 * PI / 2 && data->ray < 2 * PI))
		dir->right = 1;
	else
		dir->left = 1;
	return (dir);
}
