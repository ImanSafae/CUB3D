/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:57:21 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/22 14:26:55 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*cub_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_map_or_error(char c)
{
	//printf("c=(%c)\n", c);
	if (c == '1')
		return (1);
	if (c == '\n')
		return (0);
	if (c != 'N' && c != 'E' && c != 'S' && c != 'W' && c != 'F' && c != 'C')
		error("line starting with wrong character or open map");
	return (0);
}

void	error(char	*error_msg)
{
	printf("Error\n");
	if (error_msg != NULL)
	{
		printf("%s\n", error_msg);
	}
	exit(EXIT_FAILURE);
}

int	open_file(char	*filename)
{
	int	fd;

	fd = 0;
	if (filename == NULL)
		error("can't open. description filename is NULL");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("can't open description_file, check file validity.");
	return (fd);
}
