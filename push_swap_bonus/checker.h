/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:07:40 by junsepar          #+#    #+#             */
/*   Updated: 2023/04/25 21:59:00 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				no;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_split
{
	int		i;
	int		j;
	int		data_set;
	char	**split_in;
}	t_split;

typedef struct s_merge
{
	int	left_size;
	int	right_size;
	int	*left;
	int	*right;
}	t_merge;

typedef struct s_list
{
	t_node	*top;
	t_node	*bottom;
	int		name;
	int		size;
}	t_list;

typedef struct s_count
{
	int	count_ra;
	int	count_rb;
	int	count_push;
	int	pivot1;
	int	pivot2;

}	t_count;

void		pop_top(t_list *stack);
void		pop_bottom(t_list *stack);

// PUSH
void		push(t_list *stack, int no);
void		pa(t_list *right, t_list *left);
void		pb(t_list *left, t_list *right);
void		push_top(t_list *stack, int no);
void		push_bottom(t_list *stack, int no);

// SWAP
void		sa(t_list *stack_A);
void		sb(t_list *stack_B);
void		ss(t_list *stack_A, t_list *stack_B);

//rotate
void		ra(t_list *stack_A);
void		rb(t_list *stack_B);
void		rr(t_list *stack_A, t_list *stack_B);

//reverse_rotate
void		rra(t_list *stack_A);
void		rrb(t_list *stack_B);
void		rrr(t_list *stack_A, t_list *stack_B);

void		error_exit(void);
void		ft_putstr(char *str);
char		*get_next_line(int fd);
int			is_sort(t_list *stack_A, t_list *stack_B);
void		checker(t_list *a, t_list *b);
void		first_list(t_list **stack, int name);
void		ft_operator(t_list *a, t_list *b, char *cmd, int n);
char		**ft_split(char const *s, char c);
char		**word_dup(char **ptr, char *word, char const *s, char c);
char		*find_word(char const *s, char c);
size_t		word_count(char const *s, char c);
char		*ft_itoa(int n);
void		check_double(t_list *stack);
int			ft_strcmp(const char *s1, const char *s2);
int			nbr_len(int n);
void		merge_sort(int *arr, int size);
void		merge(int arr[], int left[], t_merge t, int right[]);
void		*clear(char **result, char **ptr);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *restrict dest, \
			const char *restrict src, size_t dstsize);
int			ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_parse(t_list *stack, int ac, char **av, int j);
#endif