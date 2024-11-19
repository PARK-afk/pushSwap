/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:05:20 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:12:15 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list *stack)
{
	int		tmp;

	if (stack->size > 1)
	{
		tmp = stack->bottom->no;
		pop_bottom(stack);
		push_top(stack, tmp);
	}
}

void	ra(t_list *stack_A)
{
	rotate(stack_A);
}

void	rb(t_list *stack_B)
{
	rotate(stack_B);
}

void	rr(t_list *stack_A, t_list *stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
}
