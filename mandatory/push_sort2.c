/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:00:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 15:52:19 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_reverse_two(t_list *b)
{
	if (sb_n(b) < sbp_n(b))
		sb(b);
}

void	sort_reverse_three(t_list *b)
{
	if (b->size < 3)
		return ;
	if (sb_n(b) < sbp_n(b) && sb_n(b) < sbpp_n(b))
	{
		sb(b);
		rb(b);
		sb(b);
		rrb(b);
		if (sb_n(b) > sbp_n(b))
			sb(b);
	}
	else if (sbp_n(b) < sb_n(b) && sbp_n(b) < sbpp_n(b))
	{
		rb(b);
		sb(b);
		rrb(b);
		if (sb_n(b) < sbp_n(b))
			sb(b);
	}
	else
	{
		if (sb_n(b) < sbp_n(b))
			sb(b);
	}
}

void	sort_a(t_list *a, int cnt)
{
	if (cnt == 2)
		two_size_sort(a);
	if (cnt == 3)
		three_size_sort(a);
}

void	sort_b(t_list *a, t_list *b, int cnt)
{
	if (cnt == 3)
		sort_reverse_three(b);
	if (cnt == 2)
		sort_reverse_two(b);
	__push(a, b, cnt);
}
