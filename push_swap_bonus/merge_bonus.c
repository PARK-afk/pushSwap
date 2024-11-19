/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:04:37 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/24 23:07:32 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
