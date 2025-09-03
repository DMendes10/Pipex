/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomende <diomende@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:28:14 by diomende          #+#    #+#             */
/*   Updated: 2025/09/03 20:05:28 by diomende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_makestring(const char *s, char c, size_t *i)
{
	size_t	size;
	char	*s2;
	int		quotes;

	quotes = 0;
	size = 0;
	while (s[size] != c && s[size] != '\0')
	{
		size++;
		if (s[size] == '\'')
		{
			quotes++;
			size++;
			while (s[size] != '\'')
				size++;
		}
	}
	s2 = ft_calloc (sizeof (char), (size - quotes * 2) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy_quotes (s2, s, (size - quotes * 2) + 1);
	(*i) += quotes * 2;
	return (s2);
}

char	*ft_makestring_quote(const char *s, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*word;

	(*i)++;
	start = *i;
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	len = *i - start;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, len + 1);
	if (s[*i] == '\'')
		(*i)++;
	return (word);
}

char	**ft_minisplit(char **a, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		if (s[i] == '\'')
			a[j] = ft_makestring_quote (s, &i);
		else
		{
			a[j] = ft_makestring(&s[i], c, &i);
			i += ft_strlen(a[j]);
		}
		if (!a[j])
			return (free_array(a), NULL);
		j++;
	}
	return (a);
}

char	**ft_split_pipex(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	if (ft_count_words_pipex(s, c, 0) < 1)
		return (NULL);
	array = ft_calloc (sizeof(char *), ft_count_words_pipex(s, c, 0) + 1);
	if (array == NULL)
		return (NULL);
	ft_minisplit(array, s, c);
	return (array);
}

size_t	ft_strlcpy_quotes(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen (src));
	while (i < size -1 && src[j])
	{
		while (src[j] == '\'')
			j++;
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
