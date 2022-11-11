/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:59:36 by itaouil           #+#    #+#             */
/*   Updated: 2022/11/11 00:25:16 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_bonus(t_data *d)
{
	int	mapend;

	d->i = d->mid_line;
	mapend = find_maplen(d);
	d->map_size = mapend - d->mid_line + 1;
	while (d->file[d->i] && d->i <= mapend)
	{
		good_line_bonus(mapend, d->i, d->mid_line, d->file[d->i]);
		d->i++;
	}
	d->map = malloc(sizeof(char *) * (mapend - d->mid_line + 2));
	d->i = d->mid_line;
	d->j = 0;
	while (d->file[d->i] && d->i <= mapend)
	{
		d->map[d->j++] = ft_strtrim(d->file[d->i], "\n");
		d->i++;
	}
	d->map[d->j] = NULL;
}

int	good_line_bonus(int end, int index, int start, char *line)
{
	int		i;
	char	*trimed;

	if (bad_charac_bonus(line))
		error("bad character in map");
	trimed = ft_strtrim(line, " \n");
	i = 0;
	while (trimed[i])
	{
		if (i == 0 || index == start || index == end
			|| i == (int)ft_strlen(trimed) - 1)
		{
			if (trimed[i] != '1' && trimed[i] != 'O' && trimed[i] != 'P'
				&& trimed[i] != 'Q' && trimed[i] != 'R' && trimed[i] != 'S'
				&& trimed[i] != 'T' && trimed[i] != 'U' && trimed[i] != 'V'
				&& trimed[i] != 'W' && trimed[i] != 'Z')
				error("opened map");
		}
		else
		{
			bad_charac_inside_bonus(trimed[i]);
		}
		i++;
	}
	free(trimed);
	return (1);
}


int	bad_charac_bonus(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '0' && c[i] != '1' && c[i] != 'N' && c[i] != 'E'
			&& c[i] != 'S' && c[i] != 'W' && c[i] != '\n'
			&& c[i] != '\t' && c[i] != ' '
            && c[i] != 'D' && c[i] != 'Z')
		{
			printf("bad carac=(%c)\n", c[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	bad_charac_inside_bonus(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'E'
		&& c != 'S' && c != 'W' && c != 'D'
		&& c != '\t' && c != ' ' && c != 'R' && c != 'Z')
	{
		printf("bad charac inside = (%c)", c);
		error("bad character inside map");
	}
	return (0);
}

int	is_map_or_error_bonus(char c)
{
	if (c == '1')
		return (1);
	if (c == '\n')
		return (0);
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W' && c != 'F' && c != 'C' && c!= 'D' && c != 'R' && c != 'Z'
			&& c != 'P' && c != 'Q' && c != 'R' && c != 'S' && c != 'T' && c != 'U' && c != 'V' && c != 'X')
	{
		printf("c = %c\n", c);
		error("line starting with wrong character or open map");
	}
	return (0);
}
