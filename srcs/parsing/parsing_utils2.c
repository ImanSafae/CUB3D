/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 14:42:08 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/09 22:02:58 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

double	get_angle(char c)
{
	if (c == 'N')
		return (PI / 2);
	if (c == 'E')
		return (2 * PI);
	if (c == 'S')
		return (3 * PI / 2);
	if (c == 'W')
		return (PI);
	return (0);
}

int	persona_position(t_cub *cub)
{
	int	i;
	int	j;

	i = 1;
	while (cub->cubmap && cub->cubmap[i] && cub->cubmap[i + 1] != NULL)
	{
		j = 0;
		while (cub->cubmap[i][j] && cub->cubmap[i][j + 1])
		{
			if (is_persona(cub->cubmap[i][j], OPEN))
			{
				cub->poz[X] = (double)j;
				cub->poz[Y] = (double)i;
				cub->angle = get_angle(cub->cubmap[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_cub(t_data *d, t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->poz[X] = 0;
	cub->poz[Y] = 0;
	cub->map_height = d->map_size;
	cub->s_key = false;
	cub->w_key = false;
	cub->a_key = false;
	cub->d_key = false;
	cub->left_arrow = false;
	cub->right_arrow = false;
	cub->fake_door_mode = false;
	cub->paintings_mode = false;
	copy_textures_tab(d, cub);
	get_color(d, cub);
	clean_texture(cub);
	parse_txtur(cub);
	persona_position(cub);
}
