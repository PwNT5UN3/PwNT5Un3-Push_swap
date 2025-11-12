/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:55:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 04:15:17 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	bubblesort(t_stk *stk, t_stat *stats, t_flag *flags)
{
	size_t	left;
	size_t	index;

	while (get_disorder(stk->vals, stk->len))
	{
		left = stk->len - 1;
		index = 0;
		while (index < left)
		{
			if (stk->vals[index] > stk->vals[index + 1])
			{
				left -= index;
				while (index--)
					r(stk, stats, flags);
				s(stk, stats, flags);
			}
			index++;
			r(stk, stats, flags);
		}
	}
}
