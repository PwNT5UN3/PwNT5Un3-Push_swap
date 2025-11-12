/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:55:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 17:06:44 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(t_stk *a, t_stk *b, t_stat *stats)
{
	size_t	index;

	while (a->len)
	{
		index = 0;
		while (index < a->len - 1)
		{
			if (a->vals[0] > a->vals[1])
				s(a);
			r(a);
			index++;
		}
		p(b, a);
	}
	while (b->len)
	{
		p(a, b);
		r(a);
	}
}
