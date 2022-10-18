/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:46:12 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/14 18:37:27 by abelhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdupcustom(const char *src, int sizeword)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (sizeword + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] && i < sizeword)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_wordlen(const char *str, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (*str && *str != c)
	{
		wordlen++;
		str++;
	}
	return (wordlen);
}

static size_t	count_words(const char *str, char c)
{
	size_t	wordsnumber;
	size_t	worlen;

	wordsnumber = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		worlen = ft_wordlen(str, c);
		str += worlen;
		if (worlen > 0)
			wordsnumber++;
	}
	return (wordsnumber);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	sizeofstring;
	char	**splited;
	size_t	wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c);
	splited = malloc(sizeof(char *) * (wordcount + 1));
	if (splited == NULL)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		while (*s == c)
			s++;
		sizeofstring = ft_wordlen(s, c);
		splited[i] = ft_strdupcustom(s, sizeofstring);
		s += sizeofstring;
		i++;
	}
	splited[i] = NULL;
	return (splited);
}
