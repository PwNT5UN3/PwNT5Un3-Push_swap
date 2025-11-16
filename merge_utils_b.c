/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 03:36:24 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/16 03:42:03 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_first_list_size_b(t_stk *stk, size_t max_len)
{
	size_t	size;

	size = 0;
	while (size < max_len - 1)
	{
		if (stk->vals[size] < stk->vals[size + 1])
			break ;
		size++;
	}
	return (size + 1);
}

size_t	get_last_list_size_b(t_stk *stk, size_t max_len)
{
	size_t	size;

	size = 0;
	while (size < max_len - 1)
	{
		if (stk->vals[stk->len - 1 - size] > stk->vals[stk->len - 2 - size])
			break ;
		size++;
	}
	return (size + 1);
}

void	big_merger(t_stk *a, t_stk *b, size_t *lst_1_len, size_t *lst_2_len)
{
	int	rotator;

	while (*lst_1_len && *lst_2_len)
	{
		if (b->vals[0] > b->vals[*lst_1_len])
		{
			p(a, b);
			*lst_1_len -= 1;
		}
		else
		{
			rotator = 0;
			while (rotator++ < *lst_1_len - 1)
				r(b);
			s(b);
			p(a, b);
			while (--rotator > 0)
				rr(b);
			*lst_2_len -= 1;
		}
	}
}
