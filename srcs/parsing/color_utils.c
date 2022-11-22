/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:59:29 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/22 17:43:20 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

long	ft_atoi_custom(const char *str)
{
	size_t	i;
	long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		error("Error with color argument\n");
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			error("Error from atoi_custom: please check color argument");
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	isnum_check(char *t)
{
	int		i;
	long	num;

	i = 0;
	while (t && t[i])
	{
		if ((t[i] < 48 || t[i] > 57) && t[i] != 43 && t[i] != 45)
		{
			error("message from isnum_check :");
			error("a character isn't in digit format");
		}
		i++;
	}
	num = ft_atoi_custom(t);
	if (num < 0 || num > 255)
		error("message from isnum_check : please check color argument limits");
	return (num);
}

void	verify_color(t_data *d, t_cub *cub, int index, int type)
{
	char	**color;
	char	*color_value;

	color = NULL;
	color_value = NULL;
	d->i = 0;
	if (d->texture_color && d->texture_color[index])
	{
		color = ft_split(d->texture_color[index], ',');
		while (color && color[d->i])
			d->i++;
		if (d->i != 3)
		{
			error("Invalid color format");
		}
		d->i = 0;
		while (color && color[d->i])
		{
			color_value = ft_strtrim(color[d->i], "\n");
			cub->rgb[type][d->i] = isnum_check(color_value);
			free(color_value);
			d->i++;
		}
	}
	free_tab(color);
}

void	get_color(t_data *d, t_cub *cub)
{
	verify_color(d, cub, 4, FLOOR);
	verify_color(d, cub, 5, CEILING);
}
