
#include "../../includes/cub3d.h"

void	check_limits(t_cub *data, t_point *wall)
{
	if (wall->x < 0)
		wall->x = 0;
	if (wall->y < 0)
		wall->y = 0;
	if (wall->x > data->map_len)
		wall->x = data->map_len;
	if (wall->y > data->map_height)
		wall->y = data->map_height;
}

int	is_wall(t_point *point, t_cub *data)
{
	int	x;
	int	y;

	x = point->x / 64;
	y = point->y / 64;
	printf("x = %d et y = %d\n", x, y);
	printf("point->x = %f et point->y = %f\n", point->x, point->y);
	if (data->cubmap[y][x] == '1')
		return (1);
	return (0);
}

t_point	*first_hor_intersection(t_cub *data, int direction, t_point *player)
{
	int		x;
	int		y;
	t_point	*wall;

	wall = malloc(sizeof(t_point));
	if (direction == UP)
		y = (player->y / 64) * 64 - 1;
	else
		y = (player->x / 64) * 64 + 64;
	x = player->x + (player->y - y) / tan(data->ray);
	wall->x = x;
	wall->y = y;
	return (wall);
}

void	next_hor_intersection(t_cub *data, int direction, t_point *wall)
{
	int		Ya;
	int		Xa;

	wall = malloc(sizeof(t_point));
	if (direction == UP)
		Ya = -64;
	else
		Ya = 64;
	Xa = Ya / tan(data->ray);
	wall->x = wall->x + Xa;
	wall->y = wall->y + Ya;
	check_limits(data, wall);
}

t_point	*last_hor_intersection(t_cub *data, int direction, t_point *player)
{
	t_point	*wall;

	wall = first_hor_intersection(data, direction, player);
	while (!is_wall(wall, data))
	{
		next_hor_intersection(data, direction, wall);
	}
	return (wall);
}

t_point	*first_ver_intersection(t_cub *data, int direction, t_point *player)
{
	int		x;
	int		y;
	t_point	*wall;

	wall = malloc(sizeof(t_point));
	if (direction == LEFT)
		x = (player->x / 64) * 64 - 1;
	else
		x = (player->x / 64) * 64 + 64;
	y = player->y + (player->x - x) * tan(data->ray);
	wall->x = x;
	wall->y = y;
	return (wall);
}

void	next_ver_intersection(t_cub *data, t_point *wall, int direction)
{
	int	Xa;
	int	Ya;

	if (direction == LEFT)
		Xa = -64;
	else
		Xa = 64;
	Ya = Xa * tan(data->ray);
	wall->x = wall->x + Xa;
	wall->y = wall->y + Ya;
	check_limits(data, wall);
}

t_point	*last_ver_intersection(t_cub *data, int direction, t_point *player)
{
	t_point	*wall;

	wall = first_ver_intersection(data, direction, player);
	while (!is_wall(wall, data))
	{
		next_ver_intersection(data, wall, direction);
	}
	return (wall);
}
