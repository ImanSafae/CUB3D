/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:18:00 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 16:59:33 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	check_xpm(char *str)
{
	char	**splited;
	int		i;

	splited = NULL;
	if (str)
		splited = ft_split(str, ".");
	while (splited && splited[i])
	{
		i++;
	}
	if (i != 2)
		error("error with texture files (check_xpm)");
	if (ft_strcmp(splited[1], "xpm"))
		error("Error with texture file extension");
	splited = free_tab(splited);
	return (0);
}