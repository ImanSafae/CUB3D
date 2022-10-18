/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:09:30 by abelhadi          #+#    #+#             */
/*   Updated: 2021/11/03 18:16:49 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_;
	char	*src_;

	dst_ = (char *)dst;
	src_ = (char *)src;
	i = 0;
	i = len;
	if (src_ < dst_)
	{
		while (i-- > 0)
			dst_[i] = src_[i];
	}
	else
	{
		ft_memcpy(dst_, src_, len);
	}
	return (dst);
}
