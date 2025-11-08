/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:24:01 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 20:59:17 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This file defines the rr methods.

void	rra(int *stack_a, int *stack_size, int *operations)
{
	int	tmp;
	int	index;

	operations[8]++;
	if (stack_size[0])
	{
		index = stack_size[0] - 1;
		tmp = stack_a[index];
		while (index > 0)
		{
			stack_a[index] = stack_a[index - 1];
			index--;
		}
		stack_a[index] = tmp;
	}
}

void	rrb(int *stack_b, int *stack_size, int *operations)
{
	int	tmp;
	int	index;

	operations[9]++;
	if (stack_size[1] > 1)
	{
		index = stack_size[1] - 1;
		tmp = stack_b[index];
		while (index > 0)
		{
			stack_b[index] = stack_b[index - 1];
			index--;
		}
		stack_b[index] = tmp;
	}
}

void	rrr(int *stack_a, int *stack_b, int *stack_size, int *operations)
{
	operations[10]++;
	rra(stack_a, stack_size, operations);
	rrb(stack_b, stack_size, operations);
	operations[8]--;
	operations[9]--;
}
