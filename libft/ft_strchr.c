/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:34:07 by abelhadi          #+#    #+#             */
/*   Updated: 2022/10/04 00:02:06 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	car;
	char	*car_;
	int		i;

	car_ = (char *)s;
	car = (char)c;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (car_[i] == car)
			return (&car_[i]);
		i++;
	}
	return (NULL);
}
