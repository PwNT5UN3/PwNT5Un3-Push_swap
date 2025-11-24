/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:33 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/22 01:57:33 by mawelsch         ###   ########.fr       */
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
	size_t	incrementor_actual;
	size_t	incrementor_check;
	size_t	index;
	size_t	highest_index;

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

void	radix_push(t_stk *a, t_stk *b)
{
	size_t	incrementor;

	incrementor = 0;
	while (incrementor < b->len)
	{	
		if (b->vals[0] % 2 == 1)
			p(a, b);
		else
		{
			r(b);
			incrementor++;
		}
	}
	incrementor = 0;
	while (incrementor < a->len)
	{
		if (a->vals[0] % 2 == 0)
			p(b, a);
		else
		{
			r(a);
			incrementor++;
		}
	}
}

void	complex_sort(t_stk *a, t_stk *b)
{
	size_t	shifter;
	int		max_runs;

	max_runs = preindex_a(a, b);
	while (max_runs--)
	{
		radix_push(a, b);
		shifter = -1;
		while (++shifter < a->len)
			a->vals[shifter] = a->vals[shifter] >> 1;
		shifter = -1;
		while (++shifter < b->len)
			b->vals[shifter] = b->vals[shifter] >> 1;
	}
	while (b->len)
		p(a, b);
}
