/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:57:53 by junsepar          #+#    #+#             */
/*   Updated: 2023/05/15 17:34:54 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_operator(t_list *a, t_list *b, char *cmd, int n)
{
	if (!ft_strncmp(cmd, "ra\n", n))
		ra(a);
	else if (!ft_strncmp(cmd, "rb\n", n))
		rb(b);
	else if (!ft_strncmp(cmd, "rr\n", n))
		rr(a, b);
	else if (!ft_strncmp(cmd, "pa\n", n))
		pa(b, a);
	else if (!ft_strncmp(cmd, "pb\n", n))
		pb(a, b);
	else if (!ft_strncmp(cmd, "rra\n", n))
		rra(a);
	else if (!ft_strncmp(cmd, "rrb\n", n))
		rrb(b);
	else if (!ft_strncmp(cmd, "rrr\n", n))
		rrr(a, b);
	else if (!ft_strncmp(cmd, "sa\n", n))
		sa(a);
	else if (!ft_strncmp(cmd, "sb\n", n))
		sb(b);
	else if (!ft_strncmp(cmd, "ss\n", n))
		ss(a, b);
	else
		error_exit();
}

void	checker(t_list *a, t_list *b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == 0)
		{
			free(line);
			line = NULL;
			break ;
		}
		ft_operator(a, b, line, BUFFER_SIZE + 1);
		free(line);
		line = NULL;
	}
	if (b->size != 0)
		return (ft_putstr("KO\n"));
	if (is_sort(a, b))
		return (ft_putstr("OK\n"));
	return (ft_putstr("KO\n"));
}

int	is_sort(t_list *stack_A, t_list *stack_B)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack_A->top;
	(void)stack_B;
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
			free (tmp);
			push_top(stack, str_set);
		}
		while (j >= 0)
			free(str[j--]);
		free(str);
	}
	check_double(stack);
}
