/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:22 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 00:59:28 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_chrono(t_cub *data)
{
	char	*chrono;

	chrono = ft_itoa(data->time_left);
	if (data->time_left > 0)
	{
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr, WIDTH_3D - 130, 30, WHITE, "Find the portal.");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr, WIDTH_3D - 130, 50, WHITE, "Time left :");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr, WIDTH_3D - 50, 50, WHITE, chrono);
		free(chrono);
	}
	else
	{
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr, WIDTH_3D - 170, 50, WHITE, "Portal is gone...");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr, WIDTH_3D - 240, 70, WHITE, "Good luck getting out of here.");
	}
}

void	transform_door(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		while (j < data->map_len)
		{
			if (data->cubmap[i][j] == 'Z')
			{
				data->cubmap[i][j] = 'D';
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	*manage_chrono(void *data)
{
	t_cub	*cub;

	cub = (t_cub *)data;
	while (cub->time_left > 0)
	{
		cub->time_left--;
		usleep(1000000);
	}
	printf("\n\n\nYOU LOSE... Good luck getting out of here.\n");
	transform_door(data);
	return (NULL);
}

void	enable_chrono_mode(t_cub *data)
{
	pthread_t	chrono;

	pthread_create(&chrono, NULL, manage_chrono, data);
	pthread_detach(chrono);
}

void	parse_painting_txtur(t_cub *c)
{
	void	*mlx;
	int		i;

	i = 0;
	while (i < 8)
	{
		c->painting_textures[i].img = NULL;
		i++;
	}
	mlx = mlx_init();
	c->txtr_mlx_ptr_bonus = mlx;
	i = 7;
	while (c->txtur && c->txtur[++i] && i < 16)
	{
		c->painting_textures[i - 8].img = mlx_xpm_file_to_image(mlx, c->txtur[i],
				&c->painting_textures[i - 8].width, &c->painting_textures[i - 8].height);
		c->painting_textures[i - 8].addr = mlx_get_data_addr(c->painting_textures[i - 8].img,
				&c->painting_textures[i - 8].bpix, &c->painting_textures[i - 8].line,
				&c->painting_textures[i - 8].endian);
		if (c->painting_textures[i - 8].img == NULL)
			error("xpm_to_image couldn't get texture image");
	}
	free_tab(c->txtur);
}

char	assign_painting(int rand)
{
	if (rand == 0)
		return ('P');
	else if (rand == 1)
		return ('Q');
	else if (rand == 2)
		return ('R');
	else if (rand == 3)
		return ('S');
	else if (rand == 4)
		return ('T');
	else if (rand == 5)
		return ('U');
	else if (rand == 6)
		return ('V');
	else
		return ('X');
}

void	textures_rng(t_cub *data)
{
	int	i;
	int	j;
	int	rand_painting_or_not;
	int	which_painting;

	i = 0;
	j = 0;
	which_painting = 0;
	while (data->cubmap && data->cubmap[i])
	{
		while (data->cubmap[i][j])
		{
			rand_painting_or_not = rand() % 14;
			if (rand_painting_or_not == 0 && data->cubmap[i][j] == '1')
			{
				which_painting = rand() % 8;
				data->cubmap[i][j] = assign_painting(which_painting);
			}
			j++;
		}
		i++;
		j = 0;
		
	}
}
