/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:23:51 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 20:59:35 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This file defines the s and p methods.

void	sa(int *stack_a, int *stack_size, int *operations)
{
	int	tmp;

	operations[0]++;
	if (stack_size[0] > 1)
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
	}
}

void	sb(int *stack_b, int *stack_size, int *operations)
{
	int	tmp;

	operations[1]++;
	if (stack_size[1] > 1)
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
	}
}

void	ss(int *stack_a, int *stack_b, int *stack_size, int *operations)
{
	operations[2]++;
	sa(stack_a, stack_size, operations);
	sb(stack_b, stack_size, operations);
	operations[0]--;
	operations[1]--;
}

void	pa(int *stack_a, int *stack_b, int *stack_size, int *operations)
{
	operations[3]++;
	if (stack_size[1] > 0)
	{
		stack_size[0]++;
		stack_a[stack_size[0]] = stack_b[stack_size[1]];
		stack_size[1]--;
	}
}

void	pb(int *stack_a, int *stack_b, int *stack_size, int *operations)
{
	operations[4]++;
	if (stack_size[0] > 0)
	{
		stack_size[1]++;
		stack_a[stack_size[1]] = stack_b[stack_size[0]];
		stack_size[0]--;
	}
}
