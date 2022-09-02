/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:16:07 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/02 11:23:27 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

int	parse_file(int descrip_fd, t_data *data)
{
	char	*line;
	int		counter;

	//printf("======================			parse file()\n");
	counter = 0;
	line = NULL;
	line = get_next_line(descrip_fd);
	while (line && ++counter)
	{
		line = cub_free(line);
		line = get_next_line(descrip_fd);
	}
//	write(1,"debu2\n",6);
	data->file = malloc(sizeof(char *) * (counter + 1));
	close(descrip_fd);
	counter = 0;
	descrip_fd = open_file(data->filename);
	line = get_next_line(descrip_fd);
//	write(1,"debu3\n",6);
	while (line)
	{
		data->file[counter] = ft_strdup(line);
		//printf("fileline=%s\n", file[counter]);
		line = cub_free(line);
		line = get_next_line(descrip_fd);
		counter++;
	}
	data->file[counter] = NULL;
	//printf("======================			parse file finish()\n");
	return (counter);
}

void	get_texture_color(t_data *d)
{
	char	**directions;
	//int i = 0;
	//printf("======================			get_texture_color()\n");
	//printf("file: %p\n", d->file);
	d->mid_line = find_mapstart(d->file);
	directions = (char *[]){"NO", "EA", "SO", "WE", "F", "C", NULL};
	d->j = -1;
	while (directions[++d->j])
	{
		//printf("d->j = %d\n", d->j);
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
		//printf("print textures: adress of tab : %p\n", d->texture_color);
	//i = 0;
	//while (d->texture_color && d->texture_color[i])
	//{
	//	printf("i=%d\n", i);
	//	printf(" textures =(%s)\n", d->texture_color[i]);
	//	i++;
	//}
}

void	get_map(t_data *d)
{
	int	mapend;

	//printf("======================			get_map()\n");
	d->i = d->mid_line;
	mapend = find_maplen(d);
	d->map_size = mapend - d->mid_line + 1;
//	printf("mid_line = %d\nmapend = %d\n", d->mid_line, mapend);
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
	//printf("======================			get_map finish()\n");
}

t_cub	*clean_map(t_data *d)
{
	t_cub	*newcub;

	//printf("======================			clean_map ()\n");
	newcub = NULL;
	newcub = (t_cub *)malloc(sizeof(t_cub));
	if (newcub == NULL)
		error("Malloc newcub structure failed");
	newcub->map_len = longest_str(d->map);
	newcub->cubmap = malloc(sizeof(char *) * (d->map_size + 1));
	//printf("mapsize=%d longestlen=%d\n", d->map_size, newcub->map_len);
	if (newcub->cubmap == NULL)
		error("Malloc cubmap failed");
	d->i = 0;
	while (d->i < (d->map_size))
	{
		//printf("print the map mallocing\n");
		newcub->cubmap[d->i] = malloc(sizeof(char) * (newcub->map_len + 1));
		newcub->cubmap[d->i][newcub->map_len] = '\0';
		ft_memset(newcub->cubmap[d->i], '$', (newcub->map_len));
		cub_strlcpy(newcub->cubmap[d->i], d->map[d->i], newcub->map_len + 1);
		d->i++;
	}
	newcub->cubmap[d->i] = NULL;
	newcub->map_height = d->map_size;
	printf("print the map before memset: (cubmap=%p)\n", d->map);
	d->i = 0;
	while (d->map && d->map[d->i])
	{
		printf("(%s)\n", d->map[d->i]);
		d->i++;
	}
	printf("print the map after memset: (cubmap=%p)\n", newcub->cubmap);
	d->i = 0;
	while (newcub->cubmap && newcub->cubmap[d->i])
	{
		printf("(%s)\n", newcub->cubmap[d->i]);
		d->i++;
	}
	//printf("======================			clean_map finish ()\n");
	return (newcub);
}

void	last_validation(t_data *data, t_cub *cub)
{
	int	i;
	int	j;

	//printf("======================			last_validation ()\n");
	if (data->map_size < 3)
		error("map inferior to three rows or inexistent");	
	i = 1;
	while (cub->cubmap && cub->cubmap[i] && cub->cubmap[i + 1] != NULL)
	{
		//printf("in loop %d\n", i);
		j = 0;
		while (cub->cubmap[i][j] == ' ' || cub->cubmap[i][j] == '\t')
			j++;
		while (cub->cubmap[i][j] && cub->cubmap[i][j + 1])
		{
			//printf("				PRINTF I=%D J=%d\n", i, j);
			map_error(cub->cubmap, i, j, OPEN);
			map_error(cub->cubmap, i, j, WALL);
			j++;
		}
		i++;
	}
	is_persona(cub->cubmap[i][j], CHECK);
//	printf("======================			last_validation finish ()\n");
}