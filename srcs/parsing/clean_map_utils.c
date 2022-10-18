/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:59:27 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 19:27:36 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

int	longest_str(char	**map)
{
	int	i;
	int	len;
	int	saved;

	len = 0;
	i = 0;
	saved = 0;
	while (map && map[i])
	{
		len = ft_strlen(map[i]);
		if (len >= saved)
			saved = len;
		i++;
	}
	return (saved);
}

size_t	cub_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	if (dstsize == 0)
		return (n);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (n);
}

void	map_error(char **map, int i, int j, int mod)
{
	if (map && (map[i][j] == '0' || is_persona(map[i][j], mod)) && mod == OPEN)
	{
		if (is_open(map[i - 1][j], OPEN) || is_open(map[i][j + 1], OPEN)
			|| is_open(map[i][j - 1], OPEN) || is_open(map[i + 1][j], OPEN))
			error("opened map or persona outside()");
	}
	if (map && (map[i][j] == ' ' || map[i][j] == '\t') && mod == WALL)
	{
		if (is_open(map[i - 1][j], WALL) || is_open(map[i][j + 1], WALL)
			|| is_open(map[i][j - 1], WALL) || is_open(map[i + 1][j], WALL))
		{
			error("No walls around space at last validation");
		}
	}
}

int	is_open(char c, int mode)
{
	if (mode == OPEN && (c == ' ' || c == '\t' || c == '$'))
		return (1);
	if (mode == WALL && (c == '0' || c == '$'))
		return (1);
	return (0);
}

int	is_persona(char c, int mode)
{
	static int		carac_counter = 0;

	if (mode == OPEN)
	{
		if (c == 'S' || c == 'E' || c == 'W' || c == 'N')
		{
			// printf("found persona (%c) counter=%d\n", c, carac_counter);
			carac_counter++;
			return (1);
		}
	}
	if (mode == CHECK && (carac_counter > 1 || carac_counter == 0))
	{
		carac_counter = 0;
		error("Delete or add a character");
	}
	if (mode == CHECK)
		carac_counter = 0;
	return (0);
}
