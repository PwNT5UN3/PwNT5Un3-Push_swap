/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:44 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/15 05:51:05 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_val(int *a, size_t len)
{
	int	i;
	int	max;

	i = 1;
	max = a[0];
	while (i < len)
	{
		if (max > a[i])
			max = a[i];
		i++;
	}
	return (max);
}

int	count_digits(int nbr)
{
	int	count;

	count = 0;
	while (nbr)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

int	ft_sqrt(int nb)
{
	int	root;

	root = 1;
	if (nb <= 0)
		return (0);
	while (root < 46340)
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}

int	*sort_(int *arr, int len)
{
	int	i;
	int	tmp;
	int	pivot;
	int	*sarr;

	sarr = (int *)ft_calloc(len, sizeof(int));
	pivot = 1;
	ft_memcpy(sarr, arr, len * sizeof(int));
	while (pivot < len)
	{
		i = pivot;
		while (i > 0 && sarr[i - 1] > sarr[i])
		{
			tmp = sarr[i];
			sarr[i] = sarr[i - 1];
			sarr[i - 1] = tmp;
			i--;
		}
		pivot++;
	}
	return (sarr);
}

// Bucket sort
void	medium_sort(t_stk *a, t_stk *b)
{
	int	*s_a;
	int	chunck_size;
	int	*chuncks[ft_sqrt(a->len)];

	s_a = sort_(a->vals, a->len);
	chunck_size = a->len / ft_sqrt(a->len);
}
