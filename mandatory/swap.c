/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:13:41 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:53:09 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sa(t_list *stack_A)
{
	swap(stack_A);
	write (1, "sa\n", 3);
	return (1);
}

int	sb(t_list *stack_B)
{
	swap(stack_B);
	write (1, "sb\n", 3);
	return (1);
}

int	ss(t_list *stack_A, t_list *stack_B)
{
	swap(stack_A);
	swap(stack_B);
	write (1, "ss\n", 3);
	return (1);
}
