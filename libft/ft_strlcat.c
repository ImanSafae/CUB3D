/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:35:06 by abelhadi          #+#    #+#             */
/*   Updated: 2021/11/01 15:35:40 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	tocopy;
	size_t	destilen;
	size_t	srclen;

	destilen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = destilen;
	if (destilen < dstsize && dstsize > 0)
	{
		tocopy = dstsize - destilen - 1;
		j = 0;
		while (src[j] != '\0' && j < tocopy)
		{
			dst[i++] = src[j++];
		}
		dst[i] = '\0';
	}
	if (destilen > dstsize)
		destilen = dstsize;
	return (destilen + srclen);
}
