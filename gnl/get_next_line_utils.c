/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:01:26 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/19 23:17:50 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fft_strdup(const char *s1)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (fft_strlen(s1) + 1));
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

char	*fft_strchr(const char *s, int c)
{
	int		i;
	char	sr;

	sr = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == sr)
			break ;
		i++;
	}
	if (s[i] == '\0' && sr != '\0')
		return (0);
	return ((char *)s + i);
}

char	*fft_strjoin(char const *s1, char const*s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = fft_strlen(s1);
	s2_len = fft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	fft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat((str + s1_len), s2, s2_len + 1);
	return (str);
}

int	fft_strlcpy(char *restrict dest, \
		const char *restrict src, int dstsize)
{
	int	idx;
	int	len;

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

int	ft_strlcat(char *restrict dst, \
		const char *restrict src, int dstsize)
{
	int	len;
	int	i;
	int	j;

	if (fft_strlen(dst) >= dstsize)
		return (fft_strlen(src) + dstsize);
	len = fft_strlen(dst) + fft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}
