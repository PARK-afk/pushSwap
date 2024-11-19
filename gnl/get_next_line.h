/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:41:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/19 23:12:48 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256 
# endif

char		*read_line(int fd, char *buf, char *backup, int n);
char		*get_next_line(int fd);
char		*need_backup(char *line);
char		*fft_strdup(const char *s1);
char		*fft_strchr(const char *s, int c);
char		*fft_strjoin(char const *s1, char const*s2);
int			fft_strlcpy(char *dst, \
			const char *src, int dstsize);
int			ft_strlcat(char *dst, \
			const char *src, int dstsize);
int			fft_strlen(const char *s);
#endif
