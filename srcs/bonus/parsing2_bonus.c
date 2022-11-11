/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:53:01 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 14:55:09 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_paintings_mode(t_data *data, char *map_name)
{
	if (!ft_strncmp(map_name, "peach_castle_bonus.cub",
			ft_strlen("peach_castle_bonus.cub")))
		data->paintings_mode = true;
	else
		data->paintings_mode = false;
}
