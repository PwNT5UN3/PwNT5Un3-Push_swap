/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_op_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:00:26 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/10 17:48:55 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stk *stk, t_stat *stats, t_flag *flags)
{
	if (flags->bench_set)
	{
		if (stk->name == 'a')
			stats->sa++;
		else
			stats->sb++;
		stats->ops++;
	}
	else
		ft_printf("s%c\n", stk->name);
}

void	p(t_stk *to, t_stk *from, t_stat *stats, t_flag *flags)
{
	if (flags->bench_set)
	{
		if (to->name == 'a')
			stats->sa++;
		else
			stats->sb++;
		stats->ops++;
	}
	else
		ft_printf("p%c\n", to->name);
}

void	r(t_stk *stk, t_stat *stats, t_flag *flags, int outside_call)
{
	if (flags->bench_set)
	{
		if (stk->name == 'a')
			stats->sa++;
		else
			stats->sb++;
		stats->ops++;
	}
	else
		ft_printf("r%c\n", stk->name);
}

void	rr(t_stk *stk, t_stat *stats, t_flag *flags, int outside_call)
{
	if (flags->bench_set)
	{
		if (stk->name == 'a')
			stats->sa++;
		else
			stats->sb++;
		stats->ops++;
	}
	else
		ft_printf("rr%c\n", stk->name);
}
