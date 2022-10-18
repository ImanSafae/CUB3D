/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:17:07 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/19 00:44:25 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* HORIZONTAL 
- Trouver coordonnees de la premiere intersection horizontale:
On commence par calculer le Y qui ne peut que prendre certaines valeurs
(car le point est forcement sur la ligne du grid), on prend donc la ligne la plus proche
vers le haut ou le bas -> déterminer la direction d'abord
On calcule ensuite le X par trigonométrie :
je commence par calculer le decalage dx entre le x du joueur et la coordonnee X
pour en deduire la coordonnee X. (tan = opposé / adjacent => adjacent = opposé / tan)

- Checker si c'est un mur

- Continuer a chercher les intersections :
meme logique que pour la premiere sauf que le decalage de Y est tjrs egal a 64 (ou -64)
Y est le plus facile a trouver car il se trouve tjrs sur le grid
puis on calcule le decalage de X de la meme facon
*/

/* VERTICAL
- Trouver coordonnées de la premiere intersection verticale :
On commence par trouver X qui est le plus facile à trouver car le point est forcément sur une ligne du grid
selon qu'on va vers la droite ou la gauche
*/

t_point	*get_first_hor_intersection(t_cub *data, t_point *player, t_directions *dir)
{
	t_point		*intersection;
	double		dy;
	double		dx;
	double		angle;

	angle = get_right_angle(data, dir, HOR);
	intersection = malloc(sizeof(t_point));
	// commencer par déterminer y qui correspond a la ligne la plus proche
	if (dir->up == 1)
		intersection->y = (((int)(player->y / 64)) * 64) - 0.000001;
	else //if (direction == DOWN)
		intersection->y = ((int)(player->y / 64) * 64) + 64;
	// déterminer x
	dy = abs_val(player->y - intersection->y);
	dx = dy / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	intersection->x = player->x + dx;
	check_limits(data, intersection);
	return (intersection);
}

void	next_hor_intersection(t_cub *data, t_point *intersection, t_directions *dir)
{
	double		dy;
	double		dx;
	double	angle;

	angle = get_right_angle(data, dir, HOR);
	dy = WALLS_SIDE;
	if (dir->up == 1)
		dy *= -1;
	dx = WALLS_SIDE / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	intersection->y += dy; // enlever cette etape et laisser en doubles ?
	intersection->x += dx;
	check_limits(data, intersection);
}

t_point	*check_hor_intersections(t_cub *data, t_point *player, t_directions *dir)
{
	t_point 		*intersection;

	intersection = get_first_hor_intersection(data, player, dir);
	while (!is_wall(data, intersection))
		next_hor_intersection(data, intersection, dir);
	return (intersection);
}

void	next_ver_intersection(t_cub *data, t_point *intersection, t_directions *dir)
{
	double		dx;
	double		dy;
	double		angle;

	angle = get_right_angle(data, dir, VERT);
	dx = 64;
	if (dir->left == 1)
		dx *= -1;
	dy = 64 * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	intersection->x += dx;
	intersection->y += dy;
	check_limits(data, intersection);
}

t_point	*get_first_ver_intersection(t_cub *data, t_point *player, t_directions *dir)
{
	t_point		*intersection;
	double		dx;
	double		dy;
	double		angle;

	angle = get_right_angle(data, dir, VERT);
	intersection = malloc(sizeof(t_point));
	if (dir->right == 1)
		intersection->x = ((int)(player->x / WALLS_SIDE) * WALLS_SIDE) + WALLS_SIDE;
	else // if (dir->left == 1)
		intersection->x = ((int)(player->x / WALLS_SIDE) * WALLS_SIDE) - 0.000001;
	dx = abs_val(player->x - intersection->x);
	dy = dx * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	intersection->y = player->y + dy;
	check_limits(data, intersection);
	return (intersection);
}

t_point	*check_ver_intersections(t_cub *data, t_point *player, t_directions *dir)
{
	t_point	*intersection;

	intersection = get_first_ver_intersection(data, player, dir);
	while (!is_wall(data, intersection))
		next_ver_intersection(data, intersection, dir);
	return (intersection);
}

// void	cardinal_rays(t_cub *data)
// {
// 	t_point	*intersection;
// 	t_point	*player;

// 	intersection = malloc(sizeof(t_point));
// 	player = malloc(sizeof(t_point));
// 	player->x = data->poz[0];
// 	player->y = data->poz[1];
// 	if (data->ray == 0 || data->ray == 2 * PI)
// 	{
// 		intersection->y = player->y;
// 		intersection->x = 
// 	}
// 	if (data->ray == PI / 2)

// 	if (data->ray == PI)

// 	if (data->ray == (3 * PI / 2))

// }
