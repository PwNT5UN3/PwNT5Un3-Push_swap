/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/13 17:54:49 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_mrg
{
	size_t	full_size;
	size_t	sublist_count;
	size_t	sublist_size;
}	t_mrg;

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
	size_t	sublists;
	size_t	lst_1_len;
	size_t	lst_2_len;

	sublists = mrg->sublist_count;
	while (sublists > 1)
	{
		lst_1_len = mrg->sublist_size;
		lst_2_len = mrg->sublist_size;
		if (stk_1->len - lst_1_len < lst_2_len)
			lst_2_len = stk_1->len - lst_1_len;
		while (lst_1_len && lst_2_len)
			small_merger(stk_1, stk_2, &lst_1_len, &lst_2_len);
		while (lst_1_len--)
			p(stk_2, stk_1);
		while (lst_2_len--)
			p(stk_2, stk_1);
		sublists -= 2;
	}
	append_leftover_chunk(stk_2, stk_1);
	mrg->sublist_count = ((mrg->sublist_count / 2) + mrg->sublist_count % 2);
	mrg->sublist_size *= 2;
}

void	merge_from_b(t_stk *stk_1, t_stk *stk_2, t_mrg *mrg)
{
	size_t	sublists;
	size_t	lst_1_len;
	size_t	lst_2_len;

	sublists = mrg->sublist_count;
	while (sublists > 1)
	{
		lst_1_len = mrg->sublist_size;
		lst_2_len = mrg->sublist_size;
		if (stk_2->len - lst_1_len < lst_2_len)
			lst_2_len = stk_2->len - lst_1_len;
		while (lst_1_len && lst_2_len)
			big_merger(stk_1, stk_2, &lst_1_len, &lst_2_len);
		while (lst_1_len--)
			p(stk_1, stk_2);
		while (lst_2_len--)
			p(stk_1, stk_2);
		sublists -= 2;
	}
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
	while (mrg.sublist_size < mrg.full_size)
	{
		if (a->len)
			merge_from_a(a, b, &mrg);
		else
			merge_from_b(a, b, &mrg);
	}
	if (b->len)
		empty_b(a, b);
}
