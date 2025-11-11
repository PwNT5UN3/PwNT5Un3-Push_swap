/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:50:08 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/11 07:25:48 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stk *stk)
{
	char const	*lbl[] = {"sa\n", "sb\n"};

	if (stk->len > 1)
	{
		swap(stk->vals);
		stk->stats->ops++;
		stk->stats->s[stk->name - 'a']++;
	}
	if (!stk->flags->bench_set)
		write(STDOUT_FILENO, lbl[stk->name - 'a'], 3);
}

void	ss(t_stk *stk_1, t_stk *stk_2)
{
	if (stk_1->len > 1 && stk_2->len > 1)
	{
		swap(stk_1->vals);
		swap(stk_2->vals);
		stk_1->stats->ops++;
		stk_1->stats->ss++;
	}
	if (!stk_1->flags->bench_set)
		write(STDOUT_FILENO, "ss\n", 3);
}

void	p(t_stk *to, t_stk *from)
{
	int			val;
	char const	*lbl[] = {"pa\n", "pb\n"};

	if (from->len)
	{
		val = pop(from->vals, &from->len);
		push(val, to->vals, &to->len);
	}
	if (!to->flags->bench_set)
		write(STDOUT_FILENO, lbl[to->name - 'a'], 3);
}

void	r(t_stk *stk)
{
	char const	*lbl[] = {"ra\n", "rb\n"};

	if (stk->len > 1)
	{
		rotate(stk->vals, stk->len);
		stk->stats->ops++;
		stk->stats->r[stk->name - 'a']++;
	}
	if (!stk->flags->bench_set)
		write(STDOUT_FILENO, lbl[stk->name - 'a'], 3);
}

void	rr(t_stk *stk)
{
	char const	*lbl[] = {"rra\n", "rrb\n"};

	if (stk->len > 1)
	{
		rrotate(stk->vals, stk->len);
		stk->stats->ops++;
		stk->stats->r[stk->name - 'a']++;
	}
	if (!stk->flags->bench_set)
		write(STDOUT_FILENO, lbl[stk->name - 'a'], 4);
}

void	rr_(t_stk *stk_1, t_stk *stk_2)
{
	if (stk_1->len > 1 && stk_2->len > 1)
	{
		rotate(stk_1->vals, stk_1->len);
		rotate(stk_2->vals, stk_2->len);
		stk_1->stats->ops++;
		stk_1->stats->rr_++;
	}
	if (!stk_1->flags->bench_set)
		write(STDOUT_FILENO, "rr\n", 3);
}

void	rrr(t_stk *stk_1, t_stk *stk_2)
{
	if (stk_1->len > 1 && stk_2->len > 1)
	{
		rrotate(stk_1->vals, stk_1->len);
		rrotate(stk_2->vals, stk_2->len);
		stk_1->stats->ops++;
		stk_1->stats->rrr++;
	}
	if (!stk_1->flags->bench_set)
		write(STDOUT_FILENO, "rrr\n", 4);
}

// --------------    TESTING ----------------------//
#include <stdio.h>

void	parr(int *arr, size_t len)
{
	printf("[");
	for (int i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
		if (i < len - 1)
			printf(", ");
	}
	printf("]\n");
}

int	main(void)
{
	int		test[] = {1, 2, 3, 4};
	int		test2[3] = {0};
	t_stat	sts;
	t_flag	flg;
	t_stk	a;
	t_stk	b; 

	sts = (t_stat){0};
	flg = (t_flag){0};
	a = (t_stk){.vals = test, .name = 'a', .len = 4, .stats = &sts, .flags = &flg};
	b = (t_stk){.vals = test2, .name = 'b', .len = 0, .stats = &sts, .flags = &flg};
	printf("original a: ");
	parr(a.vals, a.len);
	printf("\n");
	s(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	r(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	rr(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	p(&b, &a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("b: ");
	parr(b.vals, b.len);
	printf("\n");
}
