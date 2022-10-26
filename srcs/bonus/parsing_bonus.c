/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 01:51:17 by itaouil           #+#    #+#             */
/*   Updated: 2022/10/26 01:35:05 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	init_cub_bonus(t_data *d, t_cub *cub)
{
	cub->i = 0;
	cub->j = 0;
	cub->poz[X] = 0;
	cub->poz[Y] = 0;
	cub->map_height = d->map_size;
	cub->mini = malloc(sizeof(t_mlx));
	if (cub->mini == NULL)
		error("malloc cub->mini failed");
	copy_textures_tab_bonus(d, cub);
	get_color_bonus(d, cub);
	clean_texture(cub);
	parse_txtur(cub);
	persona_position(cub);
}

t_data	*init_data_bonus(t_data *data, char *filename)
{
	data = malloc(sizeof(t_data));
	if (data == NULL)
		error("malloc failed with data");
	data->map = NULL;
	data->filename = ft_strdup(filename);
	data->texture_color = NULL;
	data->texture_color = malloc(sizeof(char *) * 10);
	if (data->texture_color == NULL)
		error("malloc failed with texture_color");
	data->texture_color[9] = NULL;
	data->file = NULL;
	data->error_no = 0;
	data->found = 0;
	data->fd = 0;
	data->mid_line = 0;
	data->map_size = 0;
	return (data);
}

int	find_mapstart_bonus(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file && file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (is_map_or_error_bonus(file[i][j]))
			return (i);
		i++;
	}
	return (i);
}

t_cub	*extract_data_bonus(int descrip_fd, t_data *data)
{
	t_cub	*cub;

	parse_file(descrip_fd, data);
	if (data->file && data->file[0] == NULL)
		error("Empty file");
	get_texture_color_bonus(data);
	get_map_bonus(data);
	cub = clean_map(data);
	last_validation(data, cub);
	init_cub_bonus(data, cub);
	return (cub);
}

t_cub	*parsing_bonus(char *description_file)
{
	t_data	*data;
	t_cub	*cub;
	int		descrip_fd;

	cub = NULL;
	data = NULL;
	data = init_data_bonus(data, description_file);
	descrip_fd = open_file(description_file);
	cub = extract_data_bonus(descrip_fd, data);
	close(descrip_fd);
	free_data(data);
	free(data);
	return (cub);
}
