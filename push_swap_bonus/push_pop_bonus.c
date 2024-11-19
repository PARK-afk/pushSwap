/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:04:53 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:40:11 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_top(t_list *stack, int no)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->no = no;
	if (stack->size != 0)
	{
		tmp->next = stack->top;
		stack->top->prev = tmp;
		stack->top = tmp;
		stack->top->prev = NULL;
		tmp = NULL;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		stack->top = tmp;
		stack->bottom = tmp;
	}
	stack->size++;
}

void	push_bottom(t_list *stack, int no)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->no = no;
	if (stack->size > 0)
	{
		tmp->prev = stack->bottom;
		stack->bottom->next = tmp;
		stack->bottom = tmp;
		stack->bottom->next = NULL;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		stack->top = tmp;
		stack->bottom = tmp;
	}
	stack->size++;
}

void	pop_top(t_list *stack)
{
	t_node	*tmp;

	if (stack->size == 0)
		return ;
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	free (tmp);
	tmp = NULL;
	stack->size--;
}

void	pop_bottom(t_list *stack)
{
	t_node	*tmp;

	if (stack->size == 1)
	{
		stack->top->no = 0;
		free (stack->bottom);
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		tmp = stack->bottom;
		stack->bottom = stack->bottom->prev;
		tmp->prev = NULL;
		tmp->no = 0;
		free (tmp);
		tmp = NULL;
		stack->bottom->next = NULL;
	}
	stack->size--;
}
