/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:44 by junsepar          #+#    #+#             */
/*   Updated: 2023/05/17 17:15:42 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../gnl/get_next_line.h"

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

// POSITION
int			top(t_list *list);
int			bottom(t_list *list);

// POP
void		pop_top(t_list *stack);
void		pop_bottom(t_list *stack);
void		push_top(t_list *stack, int no);
void		push_bottom(t_list *stack, int no);

// PUSH
void		push(t_list *stack, int no);
int			pa(t_list *right, t_list *left);
int			pb(t_list *left, t_list *right);

// SWAP
int			sa(t_list *stack_A);
int			sb(t_list *stack_B);
int			ss(t_list *stack_A, t_list *stack_B);

//rotate
int			ra(t_list *stack_A);
int			rb(t_list *stack_B);
int			rr(t_list *stack_A, t_list *stack_B);

//reverse_rotate
int			rra(t_list *stack_A);
int			rrb(t_list *stack_B);
int			rrr(t_list *stack_A, t_list *stack_B);

//aia
int			ft_atoi(char *str);
char		*ft_itoa(int n);

//merge
void		check_double(t_list *stack);
void		merge_sort(int *arr, int size);
void		a_to_b(t_list *a, t_list *b, int cnt);
void		b_to_a(t_list *a, t_list *b, int cnt);
void		merge(int arr[], int left[], t_merge t, int right[]);

//position
int			top(t_list *list);
int			bottom(t_list *list);
int			sb_n(t_list *stack);
int			sbp_n(t_list *stack);
int			sbpp_n(t_list *stack);

//push_count
void		set_count(t_count *t);
void		__push(t_list *s1, t_list *s2, int cnt);
void		get_pivot(int *p1, int *p2, t_list *a, int size);
void		revers_stack(t_list *a, t_list *b, int ra, int rb);

//push_pop
void		pop_top(t_list *stack);
void		pop_bottom(t_list *stack);
void		push_top(t_list *stack, int no);
void		push_bottom(t_list *stack, int no);

//push_sort_rules
void		att(t_list *stack_A, t_list *stack_B);
void		btt(t_list *stack_A, t_list *stack_B);
void		at_bt_one(t_list *stack_A, t_list *stack_B);
void		bt_at_one(t_list *stack_A, t_list *stack_B);

//push_sort
void		two_size_sort(t_list *stack);
void		three_size_sort(t_list *stack);
void		just_three_size_sort(t_list *stack);
void		five_size_sort(t_list *stack_A, t_list *stack_B);

//push_sort2
void		sort_reverse_two(t_list *b);
void		sort_reverse_three(t_list *b);
void		sort_a(t_list *a, int cnt);
void		sort_b(t_list *a, t_list *b, int cnt);

//push_split
char		**ft_split(char const *s, char c);
char		**word_dup(char **ptr, char *word, char const *s, char c);
char		*find_word(char const *s, char c);
size_t		word_count(char const *s, char c);

//push_swap_utils
int			ft_strcmp(const char *s1, const char *s2);
int			nbr_len(int n);
size_t		ft_strlen(char *str);
void		error_exit(void);

//push_swap_utils2
void		*clear(char **result, char **ptr);
void		*ft_calloc(size_t count, size_t size);

//push_swap
void		ft_parse(t_list *stack, int ac, char **av, int j);
void		first_list(t_list **stack, int name);
int			is_sorted(t_list *stack_A, t_list *stack_B);
int			main(int ac, char **av);

//push
void		push(t_list *stack, int no);
int			pa(t_list *right, t_list *left);
int			pb(t_list *left, t_list *right);

//reverse_rotate
void		reverse_rotate(t_list *stack);
int			rra(t_list *stack_A);
int			rrb(t_list *stack_B);
int			rrr(t_list *stack_A, t_list *stack_B);

//rotate
void		rotate(t_list *stack);
int			ra(t_list *stack_A);
int			rb(t_list *stack_B);
int			rr(t_list *stack_A, t_list *stack_B);

//strset
size_t		ft_strlcpy(char *restrict dest, \
			const char *restrict src, size_t dstsize);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);

//swap
void		swap(t_list *stack);
int			sa(t_list *stack_A);
int			sb(t_list *stack_B);
int			ss(t_list *stack_A, t_list *stack_B);

#endif
