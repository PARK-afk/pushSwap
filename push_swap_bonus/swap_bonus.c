/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:05:12 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:11:56 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_list *stack)
{
	int	tmp;
	int	tmp1;

	if (stack->size > 1)
	{
		tmp = stack->bottom->no;
		tmp1 = stack->bottom->prev->no;
		pop_bottom(stack);
		pop_bottom(stack);
		push_bottom(stack, tmp);
		push_bottom(stack, tmp1);
	}
	else
		return ;
}

void	sa(t_list *stack_A)
{
	swap(stack_A);
}

void	sb(t_list *stack_B)
{
	swap(stack_B);
}

void	ss(t_list *stack_A, t_list *stack_B)
{
	swap(stack_A);
	swap(stack_B);
}
