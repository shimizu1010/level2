/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:00:00 by aoshimiz          #+#    #+#             */
/*   Updated: 2024/06/17 19:15:57 by aoshimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_words(char const *s, char c)
{
	int	wordcount;

	wordcount = 0;
	while (*s)
	{
		if (*s != c)
		{
			wordcount++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (wordcount);
}

static int	ft_length_word(char const *s, char c, int i)
{
	int	lengthofword;

	lengthofword = 0;
	while (s[i] != c && s[i++])
		lengthofword++;
	return (lengthofword);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordcount;
	char	**parsedwords;
	int		lengthofword;
	int		j;

	i = 0;
	j = -1;
	wordcount = ft_count_words(s, c);
	parsedwords = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (!parsedwords)
		return (NULL);
	while (++j < wordcount)
	{
		while (s[i] == c)
			i++;
		lengthofword = ft_length_word(s, c, i);
		parsedwords[j] = ft_substr(s, i, lengthofword);
		i += lengthofword;
	}
	parsedwords[j] = 0;
	return (parsedwords);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strsize;

	if (!s)
		return (NULL);
	strsize = ft_strlen(s);
	if (start >= strsize)
		start = strsize;
	if (len > strsize - start)
		len = strsize - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
