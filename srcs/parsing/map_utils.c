/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:47:53 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/22 21:32:49 by itaouil          ###   ########.fr       */
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

	// printf("======================			good_line(%d)\n", index);
	if (bad_charac(line))
		error("bad character in map");
	trimed = ft_strtrim(line, " \n");
	//	printf("(trimed=%s)\n", trimed);
	i = 0;
	while (trimed[i])
	{
		//printf("					i=%d et end=%d \n", index, end);
		if (i == 0 || index == start || index == end
			|| i == (int)ft_strlen(trimed) - 1)
		{
			if (trimed[i] != '1')
				error("opened map");
		}
		else
		{
			bad_charac_inside(trimed[i]);
		}
		i++;
	}
	trimed = cub_free(trimed);
//	printf("======================			good_line finish()\n");
	return (1);
}
