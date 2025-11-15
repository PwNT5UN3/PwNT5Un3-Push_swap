/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/15 00:50:27 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_mrg
{
	size_t	full_size;
	size_t	sublist_count;
	size_t	sublist_size;
}	t_mrg;

typedef struct s_lists
{
	size_t	sublists;
	size_t	l1l;
	size_t	l2l;
	int		must_rotate;
}	t_lists;

void	append_leftover_chunk(t_stk *to, t_stk *from)
{
	int	size;

	size = from->len;
	while (from->len)
		p(to, from);
	while (size--)
		r(to);
}

void	empty_b(t_stk *stk_1, t_stk *stk_2)
{
	while (stk_2->len)
		p(stk_1, stk_2);
}

void	merge_from_a(t_stk *stk_1, t_stk *stk_2, t_mrg *mrg)
{
	t_lists	lsts;

	lsts.must_rotate = 0;
	lsts.sublists = mrg->sublist_count;
	while (lsts.sublists > 1)
	{
		lsts.l1l = mrg->sublist_size;
		lsts.l2l = mrg->sublist_size;
		if (stk_1->len < lsts.l1l * 2 && stk_1->len > lsts.l1l)
		{
			lsts.l2l = stk_1->len - lsts.l1l;
			lsts.must_rotate = smol_mrg_end(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		}
		else
			small_merger(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		while (lsts.l1l--)
			p(stk_2, stk_1);
		while (lsts.l2l--)
			p(stk_2, stk_1);
		lsts.sublists -= 2;
	}
	while (lsts.must_rotate-- > 0)
		r(stk_2);
	append_leftover_chunk(stk_2, stk_1);
	mrg->sublist_count = ((mrg->sublist_count / 2) + mrg->sublist_count % 2);
	mrg->sublist_size *= 2;
}

void	merge_from_b(t_stk *stk_1, t_stk *stk_2, t_mrg *mrg)
{
	t_lists	lsts;

	lsts.must_rotate = 0;
	lsts.sublists = mrg->sublist_count;
	while (lsts.sublists > 1)
	{
		lsts.l1l = mrg->sublist_size;
		lsts.l2l = mrg->sublist_size;
		if (stk_2->len < lsts.l1l * 2 && stk_2->len > lsts.l1l)
		{
			lsts.l2l = stk_1->len - lsts.l1l;
			lsts.must_rotate = big_mrg_end(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		}
		else
			big_merger(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		while (lsts.l1l--)
			p(stk_1, stk_2);
		while (lsts.l2l--)
			p(stk_1, stk_2);
		lsts.sublists -= 2;
	}
	while (lsts.must_rotate-- > 0)
		r(stk_1);
	append_leftover_chunk(stk_1, stk_2);
	mrg->sublist_count = ((mrg->sublist_count / 2) + mrg->sublist_count % 2);
	mrg->sublist_size *= 2;
}

void	complex_sort(t_stk *a, t_stk *b)
{
	t_mrg	mrg;

	mrg.sublist_size = 1;
	mrg.sublist_count = a->len;
	mrg.full_size = mrg.sublist_count;
	while (mrg.sublist_count > 1)
	{
		if (a->len)
			merge_from_a(a, b, &mrg);
		else
			merge_from_b(a, b, &mrg);
	}
	if (b->len)
		empty_b(a, b);
}
