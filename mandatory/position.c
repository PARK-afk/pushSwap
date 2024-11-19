/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:15:58 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:51:32 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top(t_list *list)
{
	return (list->top->no);
}

int	bottom(t_list *list)
{
	return (list->bottom->no);
}

int	sb_n(t_list *stack)
{
	return (stack->bottom->no);
}

int	sbp_n(t_list *stack)
{
	return (stack->bottom->prev->no);
}

int	sbpp_n(t_list *stack)
{
	return (stack->bottom->prev->prev->no);
}
