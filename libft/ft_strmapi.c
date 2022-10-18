/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 08:08:29 by abelhadi          #+#    #+#             */
/*   Updated: 2021/11/02 08:12:10 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*strout;

	if (!s || !f)
		return (NULL);
	strout = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (strout == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		strout[index] = f(index, s[index]);
		index++;
	}
	strout[index] = '\0';
	return (strout);
}
