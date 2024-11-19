/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:15:25 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:52:58 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list *stack)
{
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->top->no;
		pop_top(stack);
		push_bottom(stack, tmp);
	}
}

int	rra(t_list *stack_A)
{
	reverse_rotate(stack_A);
	write (1, "rra\n", 4);
	return (1);
}

int	rrb(t_list *stack_B)
{
	reverse_rotate(stack_B);
	write (1, "rrb\n", 4);
	return (1);
}

int	rrr(t_list *stack_A, t_list *stack_B)
{
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
	write (1, "rrr\n", 4);
	return (1);
}
