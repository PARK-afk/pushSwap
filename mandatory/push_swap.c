/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:30 by junsepar          #+#    #+#             */
/*   Updated: 2023/05/17 16:32:29 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(t_list *stack, int ac, char **av, int j)
{
	int		i;
	char	**str;
	int		str_set;
	char	*tmp;

	i = 0;
	while (++i < ac)
	{
		str = ft_split(av[i], ' ');
		if (!str || !*str)
			error_exit();
		while (str[++j])
		{
			str_set = ft_atoi(str[j]);
			tmp = ft_itoa(str_set);
			if (ft_strcmp(str[j], tmp) == -1)
				error_exit();
			free(tmp);
			push_top(stack, str_set);
		}
		while (j >= 0)
			free(str[j--]);
		free(str);
	}
	check_double(stack);
}

void	first_list(t_list **stack, int name)
{
	*stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return ;
	(*stack)->name = name;
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;
}

int	is_sorted(t_list *stack_A, t_list *stack_B)
{
	int		i;
	t_node	*node;

	i = 0;
	if (stack_B->size != 0)
		error_exit();
	node = stack_A->top;
	while (node->next)
	{
		if (node->no < node->next->no)
			i++;
		node = node->next;
	}
	if (i != 0)
		return (0);
	return (-1);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;

	if (!(ac < 2))
	{
		first_list(&a, 'a');
		first_list(&b, 'b');
		ft_parse(a, ac, av, -1);
		if (is_sorted(a, b))
			return (0);
		if (a->size == 5)
			five_size_sort(a, b);
		else if (a->size == 3)
			just_three_size_sort(a);
		else
			a_to_b(a, b, a->size);
		if (is_sorted(a, b) == 0)
			exit(0);
	}
	exit(0);
}
