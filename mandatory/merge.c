/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:24:45 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:37:10 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_list *a, t_list *b, int cnt)
{
	t_count	t;

	set_count(&t);
	if (cnt <= 3)
	{
		sort_a(a, cnt);
		return ;
	}
	get_pivot(&t.pivot2, &t.pivot1, a, cnt);
	while (cnt-- > 0)
	{
		if (a->bottom->no > t.pivot1)
			t.count_ra += ra(a);
		else
		{
			t.count_push += pb(a, b);
			if (b->bottom->no > t.pivot2)
				t.count_rb += rb(b);
		}
	}
	revers_stack(a, b, t.count_ra, t.count_rb);
	a_to_b(a, b, t.count_ra);
	b_to_a(a, b, t.count_push - t.count_rb);
	b_to_a(a, b, t.count_rb);
}

void	b_to_a(t_list *a, t_list *b, int cnt)
{
	t_count		t;

	set_count(&t);
	if (cnt <= 2)
	{
		sort_b(a, b, cnt);
		return ;
	}
	get_pivot(&t.pivot2, &t.pivot1, b, cnt);
	while (cnt-- > 0)
	{
		if (b->bottom->no <= t.pivot2)
			t.count_rb += rb(b);
		else
		{
			t.count_push += pa(b, a);
			if (a->bottom->no <= t.pivot1)
				t.count_ra += ra(a);
		}
	}
	a_to_b(a, b, t.count_push - t.count_ra);
	revers_stack(a, b, t.count_ra, t.count_rb);
	a_to_b(a, b, t.count_ra);
	b_to_a(a, b, t.count_rb);
}

void	check_double(t_list *stack)
{
	int		*arr;
	int		i;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * stack->size);
	if (!arr)
		return ;
	i = 0;
	node = stack->top;
	while (i < stack->size)
	{
		arr[i] = node->no;
		node = node->next;
		i++;
	}
	merge_sort(arr, stack->size);
	i = 0;
	while (++i < stack->size)
		if (arr[i - 1] == arr[i])
			error_exit();
	free(arr);
}

void	merge(int arr[], int left[], t_merge t, int right[])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < t.left_size && j < t.right_size)
	{
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < t.left_size)
		arr[k++] = left[i++];
	while (j < t.right_size)
		arr[k++] = right[j++];
}

void	merge_sort(int *arr, int size)
{
	const int	mid = size / 2;
	int			i;
	t_merge		t;

	if (size < 2)
		return ;
	t.left = (int *)malloc(sizeof(int) * mid);
	if (!t.left)
		return ;
	t.right = (int *)malloc(sizeof(int) * size - mid);
	if (!t.right)
		return ;
	i = -1;
	while (++i < mid)
		t.left[i] = arr[i];
	i = mid - 1;
	while (++i < size)
		t.right[i - mid] = arr[i];
	merge_sort (t.left, mid);
	merge_sort (t.right, size - mid);
	t.left_size = mid;
	t.right_size = size - mid;
	merge (arr, t.left, t, t.right);
	free(t.left);
	free(t.right);
}
