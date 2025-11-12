/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:23:06 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 20:20:47 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			while (rotator++ < *lst_1_len)
				r(a);
			p(b, a);
			while (--rotator > 0)
				rr(a);
			*lst_2_len -= 1;
		}
	}
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
			while (rotator++ < *lst_1_len)
				r(b);
			p(a, b);
			while (--rotator > 0)
				rr(b);
			*lst_2_len -= 1;
		}
	}
}
