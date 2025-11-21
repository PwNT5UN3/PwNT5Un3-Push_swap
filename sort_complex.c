/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/21 01:23:13 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bytecount(int num)
{
	int	bytes;

	bytes = 0;
	while (num > 1)
	{
		num /= 2;
		bytes++;
	}
	return (bytes + 1);
}

int	preindex_a(t_stk *a, t_stk *b)
{
	int				incrementor_actual;
	int				incrementor_check;
	unsigned int	index;
	unsigned int	highest_index;
	int				index_bytecount;

	incrementor_actual = 0;
	highest_index = 0;
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
		if (index > highest_index)
			highest_index = index;
		incrementor_actual++;
	}
	ft_memcpy(a->vals, b->vals, a->len * sizeof(int));
	return (get_bytecount(highest_index));
}

int	need_sort(t_stk *a)
{
	int	index;

	index = 0;
	while (index++ < a->len)
	{
		if (a->vals[index] % 2 != a->vals[index + 1] % 2)
			return (1);
	}
	return (0);
}

void	complex_sort(t_stk *a, t_stk *b)
{
	int	count;
	int	incrementor;
	int	shifter;
	int	max_runs;

	max_runs = preindex_a(a, b);
	count = 0;
	while (count < max_runs)
	{
		if (get_disorder(a->vals, a->len) == 0 && get_disorder(b->vals, b->len))
			break ;
		incrementor = 0;
		if (need_sort(a))
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
		shifter = -1;
		while (++shifter < a->len)
			a->vals[shifter] = a->vals[shifter] >> 1;
		shifter = -1;
		while (++shifter < b->len)
			b->vals[shifter] = b->vals[shifter] >> 1;
		incrementor = 0;
		while (incrementor < b->len)
		{
			if (b->vals[0] % 2 == 1)
			{
				p(a, b);
			}
			else
			{
				r(b);
				incrementor++;
			}
		}
		count++;
	}
	while (b->len)
		p(a, b);
}
