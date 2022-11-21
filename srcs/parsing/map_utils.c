/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:47:53 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/21 16:19:10 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

int	find_maplen(t_data *d)
{
	int	i;
	int	j;
	int	booly;

	i = d->mid_line;
	while (d->file[i])
	{
		j = 0;
		booly = 0;
		while (d->file[i][j])
		{
			if (d->file[i][j] != '\t' && d->file[i][j] != ' ' &&
				d->file[i][j] != '\n')
				booly = 1;
			j++;
		}
		if (booly == 0 && i > 0)
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int	bad_charac(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '0' && c[i] != '1' && c[i] != 'N' && c[i] != 'E'
			&& c[i] != 'S' && c[i] != 'W' && c[i] != '\n'
			&& c[i] != '\t' && c[i] != ' ' && c[i] != 'C')
		{
			printf("bad carac=(%c)\n", c[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	bad_charac_inside(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'E'
		&& c != 'S' && c != 'W'
		&& c != '\t' && c != ' ')
	{
		printf("bad charac inside = (%c)", c);
		error("bad character inside map");
	}
	return (0);
}

int	good_line(int end, int index, int start, char *line)
{
	int		i;
	char	*trimed;

	if (bad_charac(line))
		error("bad character in map");
	trimed = ft_strtrim(line, " \n");
	i = 0;
	while (trimed[i])
	{
		if (i == 0 || index == start || index == end
			|| i == (int)ft_strlen(trimed) - 1)
		{
			if (trimed[i] != '1')
				error("opened map in goodline()");
		}
		else
		{
			bad_charac_inside(trimed[i]);
		}
		i++;
	}
	free(trimed);
	return (1);
}
