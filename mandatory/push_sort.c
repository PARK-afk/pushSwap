/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:34 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:52:15 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_size_sort(t_list *stack)
{
	if (sb_n(stack) > sbp_n(stack))
	{
		if (stack->name == 'a')
			sa(stack);
		if (stack->name == 'b')
			sb(stack);
	}
}

void	just_three_size_sort(t_list *stack)
{
	if (sb_n(stack) > sbp_n(stack) && sb_n(stack) > sbpp_n(stack))
	{
		ra(stack);
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
	else if (sbp_n(stack) > sb_n(stack) && sbp_n(stack) > sbpp_n(stack))
	{
		rra(stack);
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
	else
	{
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
}

void	three_size_sort(t_list *stack)
{
	if (sb_n(stack) > sbp_n(stack) && sb_n(stack) > sbpp_n(stack))
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
	else if (sbp_n(stack) > sb_n(stack) && sbp_n(stack) > sbpp_n(stack))
	{
		ra(stack);
		sa(stack);
		rra(stack);
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
	else
	{
		if (sb_n(stack) > sbp_n(stack))
			sa(stack);
	}
}

void	five_size_sort(t_list *stack_A, t_list *stack_B)
{
	pb(stack_A, stack_B);
	pb(stack_A, stack_B);
	just_three_size_sort(stack_A);
	sort_reverse_two(stack_B);
	if (stack_A->top->no > stack_B->bottom->no)
	{
		if (stack_A->top->next->no > stack_B->bottom->no)
			att(stack_A, stack_B);
		else
			at_bt_one(stack_A, stack_B);
	}
	else if (stack_A->top->no < stack_B->bottom->no)
	{
		if (stack_A->top->no < stack_B->bottom->prev->no)
			btt(stack_A, stack_B);
		else
			bt_at_one(stack_A, stack_B);
	}
}
