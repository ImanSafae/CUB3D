/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:11:50 by abelhadi          #+#    #+#             */
/*   Updated: 2022/08/14 19:20:33 by abelhadi         ###   ########.fr       */
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

static size_t	ft_wordlen_custom(const char *str, char c)
{
	size_t	wordlen;

	wordlen = 0;
	str++;
	wordlen++;
	while (*str)
	{
		if (*str == c && *(str + 1))
		{
			if (*(str - 1) == '"' && *(str + 1) == '"')
				wordlen++;
			else
				return (wordlen);
		}
		else
		{
			if (*str == c)
				return (wordlen);
			else
				wordlen++;
		}
		str++;
	}
	return (wordlen);
}

static size_t	count_words(const char *str, char c)
{
	size_t	wordsnumber;
	size_t	worlen;

	wordsnumber = 0;
	worlen = ft_wordlen_custom(str, c);
	if (worlen > 0)
	{
		wordsnumber++;
		str += worlen;
	}
	while (*str)
	{
		while (*str && *str == c && (*(str - 1) != '"' || *(str + 1) != '"'))
			str++;
		worlen = ft_wordlen_custom(str, c);
		str += worlen;
		if (worlen > 0)
			wordsnumber++;
	}
	return (wordsnumber);
}

char	**ft_split_c(char const *s, char c)
{
	size_t	i;
	size_t	sizeofstring;
	char	**splited;
	size_t	wordcount;

	wordcount = count_words(s, c);
	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * (wordcount + 1));
	if (splited == NULL)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		while (*s == c)
			s++;
		sizeofstring = ft_wordlen_custom(s, c);
		splited[i] = ft_strdupcustom(s, sizeofstring);
		s += sizeofstring;
		i++;
	}
	splited[i] = NULL;
	return (splited);
}
