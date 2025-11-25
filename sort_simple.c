/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:55:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/25 22:33:42 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Max's bubble sort
void	simple_sort(t_stk *a, t_stk *b)
{
	size_t	index;

	while (a->len - 2 && get_disorder(a->vals, a->len))
	{
		index = 0;
		while (index < a->len - 1)
		{
			if (a->vals[0] > a->vals[1])
				s(a);
			index++;
			r(a);
		}
		r(b);
		r(a);
	}
}
