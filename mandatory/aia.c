/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aia.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:29:05 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:29:37 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	ret;
	int	flag;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	flag = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	ret = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * flag);
}

char	*ft_itoa(int n)
{
	int			nl;
	char		*str;
	long int	nbr;

	nbr = (long int) n;
	nl = nbr_len(n);
	str = (char *)malloc(sizeof(char) * nl + 1);
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[nl] = '\0';
	while (nbr)
	{
		nl--;
		str[nl] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
