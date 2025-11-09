/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:23:58 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/09 01:52:44 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//This file defines the r methods.

void	ra(t_stk *stack_a, t_stat *operations)
{
	int	tmp;
	int	index;

	operations[5]++;
	if (stack_size[0] > 1)
	{
		index = -1;
		tmp = stack_a[0];
		while (++index < stack_size[0] - 1)
			stack_a[index] = stack_a[index + 1];
		stack_a[index] = tmp;
	}
}

void	rb(t_stk *stack_b, t_stat *operations)
{
	int	tmp;
	int	index;

	operations[6]++;
	if (stack_size[1] > 1)
	{
		index = -1;
		tmp = stack_b[0];
		while (++index < stack_size[1] - 1)
			stack_b[index] = stack_b[index + 1];
		stack_b[index] = tmp;
	}
}

void	rr(t_stk *stack_a, t_stk *stack_b, t_stat *operations)
{
	operations->rr++;
	ra(stack_a, operations);
	rb(stack_b, operations);
	operations->ra--;
	operations->rb--;
}
