/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:40 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 18:00:28 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__push(t_list *s1, t_list *s2, int cnt)
{
	if (s1->name == 'a')
	{
		while (cnt--)
			pa(s2, s1);
	}
	if (s1->name == 'b')
	{
		while (cnt--)
			pb(s1, s2);
	}
}

void	get_pivot(int *p1, int *p2, t_list *a, int size)
{
	int		i;
	int		*arr;
	t_node	*node;

	node = a->bottom;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	while (size--)
	{
		arr[i] = node->no;
		node = node->prev;
		i++;
	}
	merge_sort(arr, i);
	*p1 = arr[(i + 1) / 3 - 1];
	*p2 = arr[((i + 1) / 3) * 2 -1];
	free(arr);
}

void	set_count(t_count *t)
{
	t->count_push = 0;
	t->count_ra = 0;
	t->count_rb = 0;
}

void	revers_stack(t_list *a, t_list *b, int ra, int rb)
{
	if (ra > rb)
	{
		ra -= rb;
		while (rb-- > 0)
			rrr(a, b);
		while (ra-- > 0)
			rra(a);
	}
	else
	{
		rb -= ra;
		while (ra-- > 0)
			rrr(a, b);
		while (rb-- > 0)
			rrb(b);
	}
}
