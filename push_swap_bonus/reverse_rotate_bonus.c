/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:05:27 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:12:52 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rra(t_list *stack_A)
{
	reverse_rotate(stack_A);
}

void	rrb(t_list *stack_B)
{
	reverse_rotate(stack_B);
}

void	rrr(t_list *stack_A, t_list *stack_B)
{
	reverse_rotate(stack_A);
	reverse_rotate(stack_B);
}
