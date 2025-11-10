/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:50:08 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/10 18:24:28 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk *stk)
{
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->vals[0];
		stk->vals[0] = stk->vals[1];
		stk->vals[1] = tmp;
	}
}

void	push(t_stk *to, t_stk *from)
{
	if (from->len > 0)
	{
		to->vals[to->len] = from->vals[0];
		to->len++;
		rev_rotate(to);
		rotate(from);
		from->len--;
	}
}

void	rotate(t_stk *stk)
{
	int		tmp;
	size_t	index;

	if (stk->len > 1)
	{
		index = -1;
		tmp = stk->vals[0];
		while (++index < stk->len - 1)
			stk->vals[index] = stk->vals[index + 1];
		stk->vals[index] = tmp;
	}
}

void	rev_rotate(t_stk *stk)
{
	int		tmp;
	size_t	index;

	if (stk->len > 1)
	{
		index = stk->len;
		tmp = stk->vals[index - 1];
		while (--index > 0)
			stk->vals[index] = stk->vals[index - 1];
		stk->vals[index] = tmp;
	}
}
