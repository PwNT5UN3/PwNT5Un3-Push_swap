/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_op_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:00:09 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/11 14:56:33 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stk *stk_1, t_stk *stk_2, t_stat *stats)
{
	if (stats->bench_set)
	{
		stats->ss++;
		stats->ops++;
	}
	else
		ft_printf("ss\n");
	swap(stk_1);
	swap(stk_2);
}

void	ra(t_stk *stk_1, t_stk *stk_2, t_stat *stats)
{
	if (stats->bench_set)
	{
		stats->rr++;
		stats->ops++;
	}
	else
		ft_printf("rr\n");
	rotate(stk_1);
	rotate(stk_2);
}

void	rrr(t_stk *stk_1, t_stk *stk_2, t_stat *stats)
{
	if (stats->bench_set)
	{
		stats->rrr++;
		stats->ops++;
	}
	else
		ft_printf("rrr\n");
	rev_rotate(stk_1);
	rev_rotate(stk_2);
}
