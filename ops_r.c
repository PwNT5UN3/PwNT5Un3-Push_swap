/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:23:58 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 20:50:02 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(int *stack_a, int *stack_size, int *operations)
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

void	rb(int *stack_b, int *stack_size, int *operations)
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

void	rr(int *stack_a, int *stack_b, int *stack_size, int *operations)
{
	operations[7]++;
	ra(*stack_a, *stack_size, *operations);
	rb(*stack_a, *stack_size, *operations);
	operations[5]--;
	operations[6]--;
}
