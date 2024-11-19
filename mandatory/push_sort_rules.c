/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 01:53:36 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:52:10 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	att(t_list *stack_A, t_list *stack_B)
{
	if (stack_A->bottom->no > stack_B->bottom->no)
	{
		pa(stack_B, stack_A);
		pa(stack_B, stack_A);
	}
	else if (stack_A->bottom->no < stack_B->bottom->no)
	{
		ra(stack_A);
		pa(stack_B, stack_A);
		if (stack_A->top->no < stack_B->top->no)
		{
			pa(stack_B, stack_A);
			rra(stack_A);
		}
		else
		{
			rra(stack_A);
			pa(stack_B, stack_A);
		}
	}
}

void	btt(t_list *stack_A, t_list *stack_B)
{
	pa(stack_B, stack_A);
	pa(stack_B, stack_A);
	rra(stack_A);
	rra(stack_A);
	rra(stack_A);
}

void	at_bt_one(t_list *stack_A, t_list *stack_B)
{
	ra(stack_A);
	ra(stack_A);
	pa(stack_B, stack_A);
	if (stack_A->top->no < stack_B->top->no)
	{
		pa(stack_B, stack_A);
		rra(stack_A);
		rra(stack_A);
	}
	else
	{
		rra(stack_A);
		if (stack_A->top->no > stack_B->top->no)
		{
			rra(stack_A);
			pa(stack_B, stack_A);
		}
		else
		{
			pa(stack_B, stack_A);
			rra(stack_A);
		}
	}
}

void	bt_at_one(t_list *stack_A, t_list *stack_B)
{
	int		i;

	i = 0;
	pa(stack_B, stack_A);
	ra(stack_A);
	while (stack_A->bottom->no < stack_B->top->no)
		i += ra(stack_A);
	pa(stack_B, stack_A);
	while (i--)
		rra(stack_A);
}
