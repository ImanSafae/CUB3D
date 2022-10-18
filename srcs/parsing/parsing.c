/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:25 by abelhadi          #+#    #+#             */
/*   Updated: 2022/09/01 20:11:57 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/get_next_line.h"
#include "../../libft/libft.h"

t_data	*init_data(t_data *data, char *filename)
{
	//printf("======================			init_data()\n");
	data = malloc(sizeof(t_data));
	if (data == NULL)
		error("malloc failed with data");
	data->map = NULL;
	data->filename = ft_strdup(filename);
	//printf("data->filename =%s\n", data->filename);
	data->texture_color = NULL;
	data->texture_color = malloc(sizeof(char *) * 7);
	if (data->texture_color == NULL)
		error("malloc failed with texture_color");
	data->texture_color[6] = NULL;
	data->file = NULL;
	data->error_no = 0;
	data->found = 0;
	data->fd = 0;
	data->mid_line = 0;
	data->map_size = 0;
	//printf("======================			init_data finish()\n");
	return (data);
}

t_cub	*extract_data(int descrip_fd, t_data *data)
{
	t_cub	*cub;

	//printf("======================			extract_data()\n");
	parse_file(descrip_fd, data);
	if (data->file && data->file[0] == NULL)
		error("Empty file");
	get_texture_color(data);
	get_map(data);
	cub = clean_map(data);
	last_validation(data, cub);
	init_cub(data, cub);
	return (cub);
	//printf("======================			extract data finish()\n");
}

t_cub	*parsing(char *description_file)
{
	t_data	*data;
	t_cub	*cub;
	int		descrip_fd;

	//printf("data->filename =%s\n", data->filename);
	cub = NULL;
	data = NULL;
	data = init_data(data, description_file);
	descrip_fd = open_file(description_file);
	cub = extract_data(descrip_fd, data);
	close(descrip_fd);
	free_data(data);
	free(data);
	return (cub);
}
