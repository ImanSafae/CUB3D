/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:36:00 by abelhadi          #+#    #+#             */
/*   Updated: 2022/04/21 10:56:17 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)ft_calloc(sizeof(char), len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy (new, s1, len);
	ft_strlcat (new, s2, len);
	return (new);
}

char	*ft_strjoin_custom(char *s1, char const *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)ft_calloc(sizeof(char), len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy (new, s1, len);
	ft_strlcat (new, s2, len);
	s1 = free2(s1);
	return (new);
}