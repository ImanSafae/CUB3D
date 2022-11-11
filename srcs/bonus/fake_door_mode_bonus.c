/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:48:22 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 14:44:54 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_chrono(t_cub *data)
{
	char	*chrono;

	chrono = ft_itoa(data->time_left);
	if (data->time_left > 0)
	{
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr,
			WIDTH_3D - 130, 30, WHITE, "Find the portal.");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr,
			WIDTH_3D - 130, 50, WHITE, "Time left :");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr,
			WIDTH_3D - 50, 50, WHITE, chrono);
		free(chrono);
	}
	else
	{
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr,
			WIDTH_3D - 170, 50, WHITE, "Portal is gone...");
		mlx_string_put(data->map3d->mlx_ptr, data->map3d->win_ptr,
			WIDTH_3D - 240, 70, WHITE, "Good luck getting out of here.");
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
		c->painting_textures[i - 8].img = mlx_xpm_file_to_image(mlx,
				c->txtur[i], &c->painting_textures[i - 8].width,
				&c->painting_textures[i - 8].height);
		c->painting_textures[i - 8].addr = mlx_get_data_addr
			(c->painting_textures[i - 8].img, &c->painting_textures[i - 8].bpix,
				&c->painting_textures[i - 8].line,
				&c->painting_textures[i - 8].endian);
		if (c->painting_textures[i - 8].img == NULL)
			error("xpm_to_image couldn't get texture image");
	}
	free_tab(c->txtur);
}
