/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:55:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/10 23:21:19 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stk *stk, t_stat *stats, t_flag *flags)
{
	size_t	left;
	size_t	index;

	while (ft_get_disorder(stk->vals, stk->len))
	{
		left = stk->len - 2;
		index = 0;
		while (!left)
		{
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
			}
		}
	}
}
