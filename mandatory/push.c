/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:13:45 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:34:07 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *stack, int no)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->no = no;
	if (stack->top == NULL)
	{
		stack->top = tmp;
		stack->bottom = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		stack->bottom->next = tmp;
		tmp->prev = stack->bottom;
		stack->bottom = tmp;
		tmp->next = NULL;
	}
}

int	pa(t_list *right, t_list *left)
{
	int		no;

	if (right->size < 1)
		return (0);
	no = right->bottom->no;
	push(left, no);
	pop_bottom(right);
	left->size++;
	write (1, "pa\n", 3);
	return (1);
}

int	pb(t_list *left, t_list *right)
{
	int		no;

	no = left->bottom->no;
	if (!left || !right || left->size < 1)
		return (0);
	push(right, no);
	pop_bottom(left);
	right->size++;
	write (1, "pb\n", 3);
	return (1);
}
