/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/20 03:33:51 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preindex_a(t_stk *a, t_stk *b)
{
	int				incrementor_actual;
	int				incrementor_check;
	unsigned int	index;

	incrementor_actual = 0;
	while (incrementor_actual < a->len)
	{
		index = 0;
		incrementor_check = 0;
		while (incrementor_check < a->len)
		{
			if (a->vals[incrementor_actual] > a->vals[incrementor_check])
				index++;
			incrementor_check++;
		}
		b->vals[incrementor_actual] = index;
		incrementor_actual++;
	}
	ft_memcpy(a->vals, b->vals, a->len * sizeof(int));
}

int	need_sort(t_stk *a, int count)
{
	int	index;

	index = 0;
	while (index++ < a->len)
	{
		if (a->vals[index] % 2 != a->vals[index + 1] % 2)
			return (1);
		if (a->vals[index] % 2 == a->vals[index + 1] % 2)
			return (1);
	}
	return (0);
}

void	complex_sort(t_stk *a, t_stk *b)
{
	int	count;
	int	incrementor;
	int	shifter;

	preindex_a(a, b);
	count = 0;
	while (count < 32)
	{
		if (get_disorder(a->vals, a->len) == 0)
			break ;
		incrementor = 0;
		if (need_sort(a, count))
		{
			while (incrementor < a->len)
			{
				if (a->vals[0] % 2 == 0)
				{
					p(b, a);
				}
				else
				{
					r(a);
					incrementor++;
				}
			}
		}
		while (b->len)
			p(a, b);
		shifter = -1;
		while (++shifter < a->len)
			a->vals[shifter] = a->vals[shifter] >> 1;
		count++;
	}
}
