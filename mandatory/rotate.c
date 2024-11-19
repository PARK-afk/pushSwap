/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:13:29 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:53:01 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ra(t_list *stack_A)
{
	rotate(stack_A);
	write (1, "ra\n", 3);
	return (1);
}

int	rb(t_list *stack_B)
{
	rotate(stack_B);
	write (1, "rb\n", 3);
	return (1);
}

int	rr(t_list *stack_A, t_list *stack_B)
{
	rotate(stack_A);
	rotate(stack_B);
	write (1, "rr\n", 3);
	return (1);
}
