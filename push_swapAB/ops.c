/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 07:43:25 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/10 06:08:08 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stk *stk)
{
	int *new = (int *)ft_calloc(stk->len, sizeof(int));
	if (!new)
		return ;
	new[0] = stk->val[1];
	new[1] = stk->val[0];
	ft_memmove(&new[2], &stk->val[2], stk->len-2);
	free(stk->val);
	stk->val = new;
}

void	s(t_stk *stk, t_flag *flags, t_stat *stats)
{
	swap(stk);
	if (flags->bench_set)
	{
		stats->sa++;
		stats->ops++;
	}
	else
		ft_printf("s%c\n", stk->name);
}

void	ss(t_stk *a, t_stk *b, t_flag *flags, t_stat *stats)
{
	swap(a);
	swap(b);
	if (flags->bench_set)
	{
		stats->ss++;
		stats->ops++;
	}
	else
		ft_printf("ss\n");
}

void	p(t_stk *to, t_stk *from, t_flag *flags, t_stat *stats);
void	r(t_stk *stk, t_flag *flags, t_stat *stats);
void	rr(t_stk *stk, t_flag *flags, t_stat *stats);
void	rrr(t_stk *a, t_stk *b, t_flag *flags, t_stat *stats);

int main()
{

	int *vals= ft_calloc(3, sizeof(int));
	int *vals2= ft_calloc(3, sizeof(int));
	ft_memmove(vals, (int []){1,2,3}, 3*sizeof(int));
	ft_memmove(vals2, (int []){5,8,3}, 3*sizeof(int));
	t_stk a = {.name = 'a', .val = vals, .len = 3};
	t_stk b = {.name = 'a', .val = vals2, .len = 3};
	t_flag flags = {0};
	t_stat stats = {0};
	// s(&a, &flags, &stats);
	ss(&a, &b, &flags, &stats);
}
