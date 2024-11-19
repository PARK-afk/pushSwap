/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:05:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:04:53 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	pa(t_list *right, t_list *left)
{
	int		no;

	if (right->size < 1)
		return ;
	no = right->bottom->no;
	push(left, no);
	pop_bottom(right);
	left->size++;
}

void	pb(t_list *left, t_list *right)
{
	int		no;

	no = left->bottom->no;
	if (!left || !right || left->size < 1)
		return ;
	push(right, no);
	pop_bottom(left);
	right->size++;
}
