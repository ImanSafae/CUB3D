/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:18:00 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/11 00:09:21 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	check_xpm(char *str)
{
	char	**splited;
	int		i;

	i = 0;
	splited = NULL;
	if (str)
		splited = ft_split(str, '.');
	while (splited && splited[i])
	{
		i++;
	}
	if (i != 2)
		error("error with texture files (check_xpm)");
	if (ft_strcmp(splited[1], "xpm"))
		error("Error with texture file extension");
	free_tab(splited);
	return (0);
}
