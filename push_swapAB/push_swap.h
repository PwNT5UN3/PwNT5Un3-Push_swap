/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 04:25:09 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/10 05:17:07 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
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
	int		valid_flag;
}			t_flag;

typedef struct s_stk
{
	int		*val;
	int		len;
	char	name;
}			t_stk;

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

}			t_stat;

float		get_disorder(int *stack, int size);
int			is_num(char const *arg);
void		perror(void);
void		s(t_stk *stk, t_flag *flags, t_stat *stats);
void		ss(t_stk *a, t_stk *b, t_flag *flags, t_stat *stats);
void		p(t_stk *to, t_stk *from, t_flag *flags, t_stat *stats);
void		r(t_stk *stk, t_flag *flags, t_stat *stats);
void		rr(t_stk *stk, t_flag *flags, t_stat *stats);
void		rrr(t_stk *a, t_stk *b, t_flag *flags, t_stat *stats);
#endif
