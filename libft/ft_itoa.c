/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:41:32 by abelhadi          #+#    #+#             */
/*   Updated: 2021/11/02 15:59:02 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	digitcount(int n, char sign)
{
	int	digicount;

	digicount = 1;
	if (n >= 10)
	{
		while (n >= 10)
		{
			n = n / 10;
			digicount++;
		}
		if (sign == '-')
			digicount += 2;
		else
			digicount += 1;
	}
	else if (n < 10)
	{
		if (sign == '-')
			digicount += 2;
		else
			digicount += 1;
	}
	return (digicount);
}

static char	*creation(char *str, int n, int digicount, char sign)
{
	int	modulo;
	int	i;

	i = digicount;
	if (n < 10)
	{
		str[--i] = '\0';
		str[--i] = n + 48;
		if (sign == '-')
			str[--i] = '-';
		return (str);
	}
	str[--digicount] = '\0';
	while (n >= 10)
	{
		modulo = (n % 10) + 48;
		str[--digicount] = modulo;
		n = n / 10;
	}
	str[--digicount] = n + 48;
	if (sign == '-')
		str[--digicount] = sign;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	sign;
	int		digicount;

	if (n == 0)
		return (ft_strdup("0\0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	sign = '+';
	if (n < 0)
	{
		n = -n;
		sign = '-';
	}
	digicount = digitcount(n, sign);
	str = malloc(sizeof(char) * digicount);
	if (str == NULL)
		return (NULL);
	creation(str, n, digicount, sign);
	return (str);
}
