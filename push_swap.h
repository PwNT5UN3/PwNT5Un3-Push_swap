/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:13:02 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 01:44:39 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef enum e_strat
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX,
}	t_strat;

typedef struct s_flag
{
	t_strat	strategy;
	int		strat_set;
	int		bench_set;
	int		invalid_arg;
}	t_flag;

typedef struct s_stk
{
	int		*vals;
	size_t	len;
	char	name;
}	t_stk;

typedef struct s_stat
{
	size_t	ops;
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
	double	disorder;
	t_strat	strategy;
	int		size_a;
	int		size_b;
	int		bench_set;
}	t_stat;

int		get_modes(char **argv, t_flag *mode);
int		parse_selector(int selector, t_flag *mode);
void	invalid_arg(t_flag *mode);
int		check_option(char *value);
int		fill_stack_a(char **argv, int argc, t_stk *stack_a, t_flag *mode);
int		check_for_duplicates(t_stk *stack_a, int index_2);
double	ft_get_disorder(int *stack, int size);

//The methods
void	s(t_stk *stk, t_stat *stats);
void	p(t_stk *to, t_stk *from, t_stat *stats);
void	r(t_stk *stk, t_stat *stats);
void	rr(t_stk *stk, t_stat *stats);
void	ss(t_stk *stk_1, t_stk *stk_2, t_stat *stats);
void	ra(t_stk *stk_1, t_stk *stk_2, t_stat *stats);
void	rrr(t_stk *stk_1, t_stk *stk_2, t_stat *stats);

//The actual operations
void	swap(t_stk *stk);
void	push(t_stk *to, t_stk *from);
void	rotate(t_stk *stk);
void	rev_rotate(t_stk *stk);

//The sorting algorithms
void	bubblesort(t_stk *stk_1, t_stk *stk_2, t_stat *stats);

//testing it out
void	gulag_sort(t_stk *stk_1, t_stk *stk_2, t_stat *stats);

#endif //PUSH_SWAP_H