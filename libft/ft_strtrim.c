/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahcene <ahcene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:24:03 by abelhadi          #+#    #+#             */
/*   Updated: 2022/04/14 16:30:07 by ahcene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dst;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end - 1]) && end > 0)
		end--;
	dst = malloc(sizeof(char) * (end - start) + 1);
	if (dst == NULL || !s1)
		return (NULL);
	ft_strlcpy(dst, &s1[start], (end - start + 1));
	return (dst);
}

// No char const version of ft_strtrim to enable freeing the s1 pointer.
char	*ft_trim(char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dst;

	printf("\n=================\nFUNCTION: ft_trim()\n=================\n");
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end - 1]) && end > 0)
		end--;
	dst = malloc(sizeof(char) * (end - start) + 1);
	if (dst == NULL || !s1)
		return (NULL);
	printf("in ft_trim\n");
	ft_strlcpy(dst, &s1[start], (end - start + 1));
	printf("pointer = %p\n", s1);
	return (dst);
}
