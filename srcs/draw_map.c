#include "../includes/cub3d.h"

void	init_window(t_cub **data, int length, int height)
{
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx, length, height, "cub3d");
	(*data)->img = mlx_new_image((*data)->mlx, length, height);
	(*data)->add = mlx_get_data_addr((*data)->img, &((*data)->bpix), &((*data)->line), &((*data)->end));
	printf("bpx = %d\n", (*data)->bpix);
	printf("line = %d\n", (*data)->line);
}

void	put_pixel_to_image(t_cub *data, int x, int y, int color)
{
	char	*pixel;
	int		position;

	position = (x * (data->bpix / 8)) + (y * data->line);
	pixel = data->add + (y * data->line + x * (data->bpix / 8));
	*(unsigned int *)pixel = color;
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}


void	get_map_param(t_cub *cub)
{
	int	map_len;

	map_len = ft_strlen(cub->cubmap[0]) * 64;
	cub->map_len = map_len;
	cub->map_height = cub->map_height * 64;
}

void	draw_map(t_cub *cub)
{
	int	i_x;
	int	i_y;

	i_x = 0;
	i_y = 0;
	while (i_y < cub->map_height)
	{
		while (i_x < cub->map_len)
		{
			if ((i_x + 1) % 64 == 0 || (i_y + 1) % 64 == 0)
			{
				// printf("BLACK, x = %d et y = %d\n", i_x, i_y);
				put_pixel_to_image(cub, i_x, i_y, BLACK);
			}
			else
			{
				// printf("WHITE, x = %d et y = %d\n", i_x, i_y);
				put_pixel_to_image(cub, i_x, i_y, WHITE);
			}
			i_x++;
		}
		i_x = 0;
		i_y++;
	}
}

void	draw2d(t_cub *cub)
{
	get_map_param(cub);
	// printf("len = %d et height = %d\n", cub->map_len, cub->map_height);
	// init_window(&cub, cub->map_len, cub->map_height);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->map_len, cub->map_height, "cub3d");
	cub->img = mlx_new_image(cub->mlx, cub->map_len, cub->map_height);
	cub->add = mlx_get_data_addr(cub->img, &(cub->bpix), &(cub->line), &(cub->end));
	draw_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	mlx_loop(cub->mlx);
}
