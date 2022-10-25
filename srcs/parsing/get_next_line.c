/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:27:08 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/24 21:24:38 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include "../../includes/cub3d.h"

int	n_check(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n' || str[index] == -1)
			return (0);
		index++;
	}
	return (1);
}

char	*true_buffer(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*truebuf;
	int		ret;

	truebuf = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0 && truebuf == NULL)
		{
			return (NULL);
		}
		buff[ret] = '\0';
		if (ret != 0)
			truebuf = gnl_strjoin(truebuf, buff);
		if (n_check(buff) == 0)
		{
			break ;
		}
	}
	return (truebuf);
}

char	*n_inbuf(char	*save, int	*eof_indicator)
{
	char	*nextline;
	int		index;

	if (save == NULL)
		return (NULL);
	nextline = NULL;
	index = 0;
	while (save[index] != '\0')
	{
		if (save[index] == '\n')
		{
			index += 1;
			nextline = gnl_substr(save, 0, index);
			return (nextline);
		}
		index++;
	}
	*eof_indicator = 0;
	nextline = gnl_substr(save, 0, index);
	return (nextline);
}

char	*save_inbuf(char	*save)
{
	char	*tosave;
	int		counter;
	int		index;
	int		poolean;
	int		saved_index;

	saved_index = 0;
	poolean = 0;
	counter = 0;
	index = 0;
	while (save[index] != '\0')
	{
		if (save[index] == '\n' && save[index + 1] != '\0')
		{
			if (poolean == 0)
				poolean = index + 1;
		}
		if (poolean)
			counter += 1;
		index++;
	}
	tosave = gnl_substr(save, poolean, counter);
	free(save);
	save = NULL;
	return (tosave);
}

char	*get_next_line(int fd)
{
	char			*truebuf;
	char			*nextline;
	static char		*save = NULL;
	static int		eof_indicator = 1;

	if (fd < 0 || BUFFER_SIZE < 1 || eof_indicator == 0)
	{
		eof_indicator += 1;
		return (NULL);
	}
	truebuf = true_buffer(fd);
	if (truebuf == NULL && save == NULL)
		return (NULL);
	save = gnl_strjoin(save, truebuf);
	nextline = n_inbuf(save, &(eof_indicator));
	if (eof_indicator == 1)
		save = save_inbuf(save);
	else if (eof_indicator == 0)
		save = cub_free(save);
	truebuf = cub_free(truebuf);
	return (nextline);
}
