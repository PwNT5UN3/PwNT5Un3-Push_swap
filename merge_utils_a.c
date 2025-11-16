/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:23:06 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/16 03:37:52 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_first_list_size_a(t_stk *stk, size_t max_len)
{
	size_t	size;

	size = 0;
	while (size < max_len - 1)
	{
		if (stk->vals[size] > stk->vals[size + 1])
			break ;
		size++;
	}
	return (size + 1);
}

size_t	get_last_list_size_a(t_stk *stk, size_t max_len)
{
	size_t	size;

	size = 0;
	while (size < max_len - 1)
	{
		if (stk->vals[stk->len - 1 - size] < stk->vals[stk->len - 2 - size])
			break ;
		size++;
	}
	return (size + 1);
}

void	small_merger(t_stk *a, t_stk *b, size_t *lst_1_len, size_t *lst_2_len)
{
	int	rotator;

	while (*lst_1_len && *lst_2_len)
	{
		if (a->vals[0] < a->vals[*lst_1_len])
		{
			p(b, a);
			*lst_1_len -= 1;
		}
		else
		{
			rotator = 0;
			while (rotator++ < *lst_1_len - 1)
				r(a);
			s(a);
			p(b, a);
			while (--rotator > 0)
				rr(a);
			*lst_2_len -= 1;
		}
	}
}
