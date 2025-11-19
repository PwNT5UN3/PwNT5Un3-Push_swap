/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:42:31 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/19 04:42:36 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_fitting_pos(t_stk *b, int val, int pivot)
{
	int	iterator;
	int	comp;

	iterator = 0;
	while (iterator < b->len - 1)
	{
		comp = iterator - 1;
		if (iterator == 0)
			comp = b->len - 1;
		if (iterator == pivot
			&& (val > b->vals[iterator] || val < b->vals[comp]))
			return (iterator);
		if (val > b->vals[iterator]
			&& val < b->vals[comp])
			return (iterator);
		iterator++;
	}
	return (iterator);
}

int	get_pivot(t_stk *b)
{
	int	pivot;

	pivot = 0;
	if (b->len == 0)
		return (0);
	if (b->len > 0)
		if (b->vals[0] >= b->vals[b->len - 1])
			return (0);
	while (pivot < b->len - 1)
	{
		if (b->vals[pivot] < b->vals[pivot + 1])
			break ;
		pivot++;
	}
	return (pivot + 1);
}

void	complex_sort(t_stk *a, t_stk *b)
{
	int	gyro;
	int	pivot;

	pivot = 0;
	while (a->len)
	{
		gyro = get_fitting_pos(b, a->vals[0], pivot);
		while (gyro < b->len && gyro > 0)
		{
			if (gyro < (b->len / 2))
			{
				r(b);
				gyro--;
			}	
			else
			{
				rr(b);
				gyro++;
			}
		}
		p(b, a);
		pivot = get_pivot(b);
	}
	while (pivot < b->len && pivot > 0)
	{
		if (pivot > (b->len / 2))
		{
			rr(b);
			pivot++;
		}	
		else
		{
			r(b);
			pivot--;
		}
	}
	while (b->len)
		p(a, b);
}
