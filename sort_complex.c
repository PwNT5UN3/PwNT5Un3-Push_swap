/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/16 03:43:21 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_mrg
{
	size_t	full_size;
	size_t	sublist_count;
	size_t	sublist_size;
	int		appended_last_chunk;
}	t_mrg;

typedef struct s_lists
{
	size_t	sublists;
	size_t	l1l;
	size_t	l2l;
	int		must_rotate;
}	t_lists;

void	append_leftover_chunk(t_stk *to, t_stk *from, t_mrg *mrg)
{
	int	size;

	size = from->len;
	while (from->len)
		p(to, from);
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
		if (lsts.sublists == mrg->sublist_count)
		{
			if (--mrg->appended_last_chunk == 0)
			{
				lsts.l1l = get_first_list_size_a(stk_1, mrg->sublist_size / 2);
			}
			else
				lsts.l1l = get_first_list_size_a(stk_1, mrg->sublist_size);
		}
		if (lsts.sublists == 2)
			lsts.l2l = get_last_list_size_a(stk_1, mrg->sublist_size);
		small_merger(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		while (lsts.l1l--)
			p(stk_2, stk_1);
		while (lsts.l2l--)
			p(stk_2, stk_1);
		lsts.sublists -= 2;
	}
	if (lsts.sublists == 1)
		mrg->appended_last_chunk = 1;
	append_leftover_chunk(stk_2, stk_1, mrg);
	mrg->sublist_size *= 2;
	mrg->sublist_count = ((mrg->sublist_count / 2) + mrg->sublist_count % 2);
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
		if (lsts.sublists == mrg->sublist_count)
		{
			if (--mrg->appended_last_chunk == 0)
			{
				lsts.l1l = get_first_list_size_b(stk_2, mrg->sublist_size / 2);
			}
			else
				lsts.l1l = get_first_list_size_b(stk_2, mrg->sublist_size);
		}
		if (lsts.sublists == 2)
			lsts.l2l = get_last_list_size_b(stk_2, mrg->sublist_size);
		big_merger(stk_1, stk_2, &lsts.l1l, &lsts.l2l);
		while (lsts.l1l--)
			p(stk_1, stk_2);
		while (lsts.l2l--)
			p(stk_1, stk_2);
		lsts.sublists -= 2;
	}
	if (lsts.sublists == 1)
		mrg->appended_last_chunk = 1;
	append_leftover_chunk(stk_1, stk_2, mrg);
	mrg->sublist_size *= 2;
	mrg->sublist_count = ((mrg->sublist_count / 2) + mrg->sublist_count % 2);
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
