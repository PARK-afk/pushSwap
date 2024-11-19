/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:59 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:50:09 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (*s1 == '+')
		s1++;
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

int	nbr_len(int n)
{
	int		nl;
	long	nbr;

	nbr = (long) n;
	nl = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr *= -1;
		nl++;
	}
	while (nbr)
	{
		nbr /= 10;
		nl++;
	}
	return (nl);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_exit(void)
{
	write (1, "Error\n", 6);
	exit (-1);
}
