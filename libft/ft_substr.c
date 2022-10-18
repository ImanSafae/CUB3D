/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:59 by abelhadi          #+#    #+#             */
/*   Updated: 2021/11/01 18:13:47 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	truelen;

	truelen = ft_strlen(s);
	if (len > truelen)
		len = truelen;
	if (start >= truelen)
	{
		ptr = malloc(sizeof(char) * 1);
		*ptr = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while ((*s && i < len) && start < truelen)
	{
		ptr[i] = s[start];
		s++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
