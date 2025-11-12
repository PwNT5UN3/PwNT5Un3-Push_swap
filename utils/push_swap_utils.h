/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:26:55 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/12 04:29:49 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

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
	t_stat	*sts;
	t_flag	*flgs;
	int		*vals;
	size_t	len;
	size_t	cap;
	char	name;
}			t_stk;

int			parse_bench(t_flag *flags, char const *arg);
int			parse_strat(t_flag *flags, char const *arg);
int			parse_flag(t_flag *flags, int *pos, int argc, char const *argv[]);
int			parse_numargs(t_stk *stk, int *pos, int argc, char const *argv[]);
float		get_disorder(int *stack, int size);
int			is_num(char const *arg);
void		pbench(t_stat *sts);
void		perror(void);

void		s(t_stk *stk);
void		ss(t_stk *stk_1, t_stk *stk_2);
void		p(t_stk *to, t_stk *from);
void		r(t_stk *stk);
void		rr(t_stk *stk);
void		rr_(t_stk *stk_1, t_stk *stk_2);
void		rrr(t_stk *stk_1, t_stk *stk_2);

void		swap(int *arr);
void		rotate(int *arr, size_t len);
void		rrotate(int *arr, size_t len);
int			pop(int *arr, size_t *len);
void		push(int val, int *arr, size_t *len);

#endif
