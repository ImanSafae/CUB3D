
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

float	get_right_angle(t_cub *data, t_directions *dir, int grid)
{
	float	angle;

	angle = data->ray;
	if (dir->up == 1 && dir->right == 1 && grid == HOR)
		angle = data->ray;
	if (dir->up == 1 && dir->left == 1 && grid == HOR)
	{
		angle = PI - data->ray;
	}
	if (dir->down == 1 && dir->left == 1 && grid == HOR)
	{
		angle = data->ray - PI;
	}
	if (dir->down == 1 && dir->right == 1 && grid == HOR)
	{
		angle = (2 * PI) - data->ray;
		// printf("down right hor\n");
	}
	if (dir->up == 1 && dir->right == 1 && grid == VERT)
	{
		angle = data->ray;
	}
	if (dir->up == 1 && dir->left == 1 && grid == VERT)
	{
		// printf("up left vert\n");
		angle = PI - data->ray;
	}
	if (dir->down == 1 && dir->left == 1 && grid == VERT)
	{
		// printf("down left vert\n");
		angle = data->ray - PI;
	}
	if (dir->down == 1 && dir->right == 1 && grid == VERT)
	{
		// printf("down right vert\n");
		angle = (2 * PI) - data->ray;
	}
	// if (data->ray == PI)
	// 	printf("il y a moktar sous roche\n");
	return (angle);
}

t_directions	*get_directions(t_cub *data)
{
	t_directions	*dir;

	dir = malloc(sizeof(t_directions));
	dir->down = 0;
	dir->up = 0;
	dir->left = 0;
	dir->right = 0;
	if (data->ray == 0 || data->ray == PI || data->ray == PI / 2 || data->ray == 3 * PI / 2)
	{
		//cette condition ne devrait jamais etre checkée
		printf("can't do this angle yet\n");
		exit(EXIT_FAILURE);
	}
	if (data->ray > 0 && data->ray < PI)
	{
		printf("up +");
		dir->up = 1;
	}
	else
	{
		printf("down +");
		dir->down = 1;
	}
	if ((data->ray > 0 && data->ray < PI / 2) || (data->ray > 3 * PI / 2 && data->ray < 2 * PI))
	{
		printf("right\n");
		dir->right = 1;
	}
	else
	{
		printf("left\n");
		dir->left = 1;
	}
	return (dir);
}

void	check_limits(t_cub *data, t_point *point)
{
	if (point->x < 0)
		point->x = 0;
	if (point->y < 0)
		point->y = 0;
	if (point->x > data->map_len)
		point->x = data->map_len - 64;
	if (point->y > data->map_height)
		point->y = data->map_height - 64;
}

int	is_wall(t_cub *data, t_point *point, t_directions *dir, int grid)
{
	int	x;
	int	y;

	// x = (int)(point->x / 64);
	// y = (int)(point->y / 64);
	y = get_y_coordinate(data, point->y);
	x = get_x_coordinate(data, point->x, y);
	if (dir->down == 1 && grid == HOR)
		y++;
	if (dir->right == 1 && grid == VERT)
		x++;
	if (x >= data->map_len / 64 - 1)
		x = (data->map_len / 64) - 1;
	if (y >= data->map_height / 64 - 1)
		y = (data->map_height / 64) - 1;
	if (data->cubmap[y][x] == '1')
		return (1);
	return (0);

}

t_point	*get_first_hor_intersection(t_cub *data, t_point *player, t_directions *dir)
{
	t_point	*first_intersection;
	int		y;
	int		dy;
	int		x;
	int		dx;
	float	angle;

	angle = get_right_angle(data, dir, HOR);
	first_intersection = malloc(sizeof(t_point));
	// commencer par déterminer y qui correspond a la ligne la plus proche
	if (dir->up == 1)
	{
		y = (int)(player->y / 64) * 64 - 1;
	}
	else //if (direction == DOWN)
		y = (int)(player->y / 64) * 64 + 63;
	// déterminer x
	dy = abs_val(player->y - y);
	dx = dy / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	x = player->x + dx;
	first_intersection->x = (float)x;
	first_intersection->y = (float)y;
	check_limits(data, first_intersection);
	return (first_intersection);
}

void	next_hor_intersection(t_cub *data, t_point *intersection, t_directions *dir)
{
	int		dy;
	int		dx;
	int		x;
	int		y;
	float	angle;

	angle = get_right_angle(data, dir, HOR);
	dy = 64;
	if (dir->up == 1)
		dy *= -1;
	dx = 64 / tan(angle);
	if (dir->left == 1)
		dx *= -1;
	y = (int)(intersection->y) + dy; // enlever cette etape et laisser en floats ?
	x = (int)(intersection->x) + dx;
	intersection->x = (float)x;
	intersection->y = (float)y;
	check_limits(data, intersection);
}

t_point	*check_hor_intersections(t_cub *data, t_point *player, t_directions *dir)
{
	t_point 		*intersection;

	intersection = get_first_hor_intersection(data, player, dir);
	if (is_wall(data, intersection, dir, HOR))
		return (intersection);
	while (!is_wall(data, intersection, dir, HOR))
	{
		next_hor_intersection(data, intersection, dir);
	}
	return (intersection);
}

void	next_ver_intersection(t_cub *data, t_point *intersection, t_directions *dir)
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	float	angle;

	angle = get_right_angle(data, dir, VERT);
	dx = 64;
	if (dir->left == 1)
		dx *= -1;
	dy = 64 * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	x = (int)(intersection->x) + dx; // enlever cette etape et laisser en floats ?
	y = (int)(intersection->y) + dy;
	intersection->x = (float)x;
	intersection->y = (float)y;
	check_limits(data, intersection);
}

t_point	*get_first_ver_intersection(t_cub *data, t_point *player, t_directions *dir)
{
	t_point	*intersection;
	int		x;
	int		y;
	int		dx;
	int		dy;
	float	angle;

	angle = get_right_angle(data, dir, VERT);
	intersection = malloc(sizeof(t_point));
	if (dir->right == 1)
		x = (int)(player->x / 64) * 64 + 63;
	else // if (dir->left == 1)
		x = (int)(player->x / 64) * 64 - 1;
	dx = abs_val(player->x - x);
	dy = dx * tan(angle);
	if (dir->up == 1)
		dy *= -1;
	y = player->y + dy;
	intersection->x = (float)x;
	intersection->y = (float)y;
	check_limits(data, intersection);
	return (intersection);
}

t_point	*check_ver_intersections(t_cub *data, t_point *player, t_directions *dir)
{
	t_point	*intersection;

	intersection = get_first_ver_intersection(data, player, dir);
	if (is_wall(data, intersection, dir, VERT))
		return (intersection);
	while (!is_wall(data, intersection, dir, VERT))
	{
		next_ver_intersection(data, intersection, dir);
	}
	return (intersection);
}

float	get_distance(float ray, t_point *player, t_point *wall)
{
	float	distance;

	distance = abs_val((player->x - wall->x) / (cos(ray)));
	return (abs_val(distance));
}

void	paint_ray(t_cub *data)
{
	t_point			*player;
	t_point			*hor_intersection;
	t_point			*ver_intersection;
	t_directions	*dir;
	float			hor_distance;
	float			ver_distance;

	printf("angle = %f\n", data->angle);
	dir  = get_directions(data);
	player = malloc(sizeof(t_point));
	player->x = data->poz[0];
	player->y = data->poz[1];
	hor_intersection = check_hor_intersections(data, player, dir);
	hor_distance = get_distance(data->ray, player, hor_intersection);
	ver_intersection = check_ver_intersections(data, player, dir);
	ver_distance = get_distance(data->ray, player, ver_intersection);
	if (ver_distance < hor_distance)
		dda(data, player, ver_intersection, GREEN);
	else
		dda(data, player, hor_intersection, RED);
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

void	modulo_two_pi(float *angle)
{
	while ((*angle) > 2 * PI)
		(*angle) = (*angle) - (2 * PI);
	while ((*angle) < 0)
		(*angle) = (2 * PI) + (*angle);
}

void	paint_fov(t_cub *data)
{
	float	fov_ray;
	float	incr;

	modulo_two_pi(&data->angle);
	data->ray = data->angle;
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
