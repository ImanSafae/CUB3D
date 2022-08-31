/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:48:58 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/17 13:40:00 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include "../../includes/cub3d.h"

void	*gnl_free(char	*new)
{
	free(new);
	new = NULL;
	return (NULL);
}

void	*gnl_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	ptr = malloc(count * size);
	if (ptr)
	{
		while (i < size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

size_t	gnl_strlen(char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (start == 0 && len == 0)
		return (NULL);
	ptr = gnl_calloc(sizeof(char), len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	len;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = gnl_substr("\0", 0, 1);
	len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	new = gnl_calloc(sizeof(char), len);
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	s1 = NULL;
	return (new);
}
