/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:29:48 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:53:06 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *restrict dest, \
		const char *restrict src, size_t dstsize)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (src[len])
		len++;
	while (src[idx] && idx + 1 < dstsize)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dest[idx] = '\0';
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	if (n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_l;
	char	*ss;
	char	*str;

	ss = (char *)s;
	if (s == NULL )
		return (0);
	if (len <= 0 || (unsigned int)ft_strlen(ss) < start)
		return (ft_strdup(""));
	s_l = ft_strlen(ss + start);
	if (s_l < len)
		len = s_l;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
