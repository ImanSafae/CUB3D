/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:16:07 by abelhadi          #+#    #+#             */
/*   Updated: 2022/11/11 00:25:06 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

int	parse_file(int descrip_fd, t_data *data)
{
	char	*line;
	int		counter;

	counter = 0;
	line = NULL;
	line = get_next_line(descrip_fd);
	while (line && ++counter)
	{
		free(line);
		line = get_next_line(descrip_fd);
	}
	data->file = malloc(sizeof(char *) * (counter + 1));
	close(descrip_fd);
	counter = 0;
	descrip_fd = open_file(data->filename);
	line = get_next_line(descrip_fd);
	while (line)
	{
		data->file[counter] = ft_strdup(line);
		free(line);
		line = get_next_line(descrip_fd);
		counter++;
	}
	data->file[counter] = NULL;
	return (counter);
}

void	get_texture_color(t_data *d)
{
	char	**directions;

	d->mid_line = find_mapstart(d->file);
	directions = (char *[]){"NO", "EA", "SO", "WE", "F", "C", NULL};
	d->j = -1;
	while (directions[++d->j])
	{
		d->i = 0;
		d->found = 0;
		while (d->i < d->mid_line)
		{
			if (get_texture(d, d->file[d->i], directions[d->j], d->j))
				d->found++;
			d->i++;
		}
		if (d->found > 1 || !d->found)
			error("repeated or missing texture, delete/add one and restart");
	}
}

void	get_map(t_data *d)
{
	int	mapend;

	d->i = d->mid_line;
	mapend = find_maplen(d);
	d->map_size = mapend - d->mid_line + 1;
	while (d->file[d->i] && d->i <= mapend)
	{
		good_line(mapend, d->i, d->mid_line, d->file[d->i]);
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

t_cub	*clean_map(t_data *d)
{
	t_cub	*newcub;

	newcub = NULL;
	newcub = (t_cub *)malloc(sizeof(t_cub));
	if (newcub == NULL)
		error("Malloc newcub structure failed");
	newcub->map_len = longest_str(d->map);
	newcub->cubmap = malloc(sizeof(char *) * (d->map_size + 1));
	if (newcub->cubmap == NULL)
		error("Malloc cubmap failed");
	d->i = 0;
	while (d->i < (d->map_size))
	{
		newcub->cubmap[d->i] = malloc(sizeof(char) * (newcub->map_len + 1));
		newcub->cubmap[d->i][newcub->map_len] = '\0';
		ft_memset(newcub->cubmap[d->i], '$', (newcub->map_len));
		cub_strlcpy(newcub->cubmap[d->i], d->map[d->i], newcub->map_len + 1);
		d->i++;
	}
	newcub->cubmap[d->i] = NULL;
	newcub->map_height = d->map_size;
	return (newcub);
}

void	last_validation(t_data *data, t_cub *cub)
{
	int	i;
	int	j;

	if (data->map_size < 3)
		error("map inferior to three rows or inexistent");
	i = 1;
	while (cub->cubmap && cub->cubmap[i] && cub->cubmap[i + 1] != NULL)
	{
		j = 0;
		while (cub->cubmap[i][j] == ' ' || cub->cubmap[i][j] == '\t')
			j++;
		while (cub->cubmap[i][j] && cub->cubmap[i][j + 1])
		{
			map_error(cub->cubmap, i, j, OPEN);
			map_error(cub->cubmap, i, j, WALL);
			j++;
		}
		i++;
	}
	is_persona(cub->cubmap[i][j], CHECK);
}
