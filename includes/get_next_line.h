/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:30:05 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/16 19:11:00 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 200

int		n_check(char *str);
void	*gnl_free(char	*new);
char	*get_next_line(int fd);
char	*save_inbuf(char	*pointer);
char	*n_inbuf(char	*pointer, int	*eof_indicator);
char	*true_buffer(int fd);
void	*gnl_calloc(size_t count, size_t size);
size_t	gnl_strlen(char *s);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);
#endif