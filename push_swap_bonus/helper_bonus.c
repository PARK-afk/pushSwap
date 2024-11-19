/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:18:41 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:23:39 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_exit(void)
{
	write (1, "Error\n", 6);
	exit (-1);
}

void	*clear(char **result, char **ptr)
{
	while (result <= ptr)
	{
		free(*ptr);
		ptr--;
	}
	free(result);
	return (NULL);
}
