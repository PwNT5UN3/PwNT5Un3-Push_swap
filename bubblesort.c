/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:55:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 02:03:44 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stk *stk_1, t_stk *stk_2, t_stat *stats)
{
	size_t	index;

	while (stk_1->len)
	{
		index = 0;
		while (index < stk_1->len - 1)
		{
			if (stk_1->vals[0] > stk_1->vals[1])
				s(stk_1, stats);
			r(stk_1, stats);
			index++;
		}
		p(stk_2, stk_1, stats);
	}
	while (stk_2->len)
	{
		p(stk_1, stk_2, stats);
		r(stk_1, stats);
	}
}
