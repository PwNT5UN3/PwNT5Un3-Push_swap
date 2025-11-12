/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gulag_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:16:38 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 02:27:57 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gulag_sort(t_stk *stk_1, t_stk *stk_2, t_stat *stats)
{
	size_t	index;

	while (ft_get_disorder(stk_1->vals, stk_1->len))
	{
		index = 0;
		while (index < stk_1->len - 1)
		{
			if (stk_1->vals[0] > stk_1->vals[1])
			{
				r(stk_1, stats);
				p(stk_2, stk_1, stats);
				rr(stk_1, stats);
				index--;
			}
			else
				r(stk_1, stats);
			index++;
		}
		r(stk_1, stats);
		while (stk_2->len)
			p(stk_1, stk_2, stats);
	}
}
