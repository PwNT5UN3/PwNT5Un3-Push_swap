/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:13:02 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/11 07:26:43 by abalcu           ###   ########.fr       */
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
}			t_strat;

typedef struct s_flag
{
	t_strat	strategy;
	int		strat_set;
	int		bench_set;
	int		invalid_arg;
}			t_flag;

typedef struct s_stat
{
	size_t	ops;
	size_t	s[2];
	size_t	p[2];
	size_t	r[2];
	size_t	rr[2];
	size_t	ss;
	size_t	rr_;
	size_t	rrr;
	double	disorder;
	t_strat	strategy;
	int		size_a;
	int		size_b;
}			t_stat;

typedef struct s_stk
{
	t_stat	*stats;
	t_flag	*flags;
	int		*vals;
	size_t	len;
	char	name;
}			t_stk;

int			get_modes(char **argv, t_flag *mode);
int			parse_selector(int selector, t_flag *mode);
void		invalid_arg(t_flag *mode);
int			check_option(char *value);
int			fill_stack_a(char **argv, int argc, t_stk *stack_a, t_flag *mode);
int			check_for_duplicates(t_stk *stack_a, int index_2);
double		ft_get_disorder(int *stack, int size);

// The methods
void		s(t_stk *stk);
void		ss(t_stk *stk_1, t_stk *stk_2);
void		p(t_stk *to, t_stk *from);
void		r(t_stk *stk);
void		rr(t_stk *stk);
void		rr_(t_stk *stk_1, t_stk *stk_2);
void		rrr(t_stk *stk_1, t_stk *stk_2);

// The actual operations
void		swap(int *arr);
void		rotate(int *arr, size_t len);
void		rrotate(int *arr, size_t len);
int			pop(int *arr, size_t *len);
void		push(int val, int *arr, size_t *len);

// The sorting algorithms
void		bubblesort(t_stk *stk, t_stat *stats, t_flag *flags);

#endif // PUSH_SWAP_H
