/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:24:01 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/09 13:32:04 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//This file defines the rr methods.

void	rra(t_stk *stack_a, t_stat *operations)
{
	int	tmp;
	int	index;

	operations->rra++;
	if (stack_a->len > 1)
	{
		index = stack_a->len - 1;
		tmp = stack_a->vals[index];
		while (index > 0)
		{
			stack_a->vals[index] = stack_a->vals[index - 1];
			index--;
		}
		stack_a->vals[index] = tmp;
	}
}

void	rrb(t_stk *stack_b, t_stat *operations)
{
	int	tmp;
	int	index;

	operations->rrb++;
	if (stack_b->len > 1)
	{
		index = stack_b->len - 1;
		tmp = stack_b->vals[index];
		while (index > 0)
		{
			stack_b->vals[index] = stack_b->vals[index - 1];
			index--;
		}
		stack_b->vals[index] = tmp;
	}
}

void	rrr(t_stk *stack_a, t_stk *stack_b, t_stat *operations)
{
	operations->rrr++;
	rra(stack_a, operations);
	rrb(stack_b, operations);
	operations->rra--;
	operations->rrb--;
}
