/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:05:42 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:13:34 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*word;

	if (!*s || !s)
		return (ft_calloc(sizeof(char *), 1));
	ptr = (char **)ft_calloc(sizeof(char *), word_count(s, c) + 1);
	if (!ptr)
		return (NULL);
	word = find_word(s, c);
	return (word_dup(ptr, word, s, c));
}

char	**word_dup(char **ptr, char *word, char const *s, char c)
{
	char	**result;

	result = ptr;
	while (*s)
	{
		if (*s == c && s > word)
		{
			*ptr = ft_substr(word, 0, s - word);
			if (!*ptr)
				return (clear(result, ptr));
			word = find_word(s, c);
			ptr++;
		}
		s++;
	}
	if (*word)
	{
		*ptr = ft_substr(word, 0, s - word);
		if (!*ptr)
			return (clear(result, ptr));
		ptr++;
	}
	*ptr = NULL;
	return (result);
}

char	*find_word(char const *s, char c)
{
	while (*s == c)
		s++;
	return ((char *)s);
}

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 1;
	while (*s)
	{
		if (*s != c && flag == 1)
		{
			flag = 0;
			i++;
		}
		else if (*s == c)
			flag = 1;
		s++;
	}
	return (i);
}
