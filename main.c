/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:22 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 21:17:55 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(int *stack_a, int index_2)
{
	int	searchhead;

	searchhead = -1;
	while (++searchhead < index_2)
		if (stack_a[searchhead] == stack_a[index_2])
			return (0);
	return (1);
}

//This function puts all objects into the array stack_a.
int	fill_stack_a(char **argv, int *stack_size, int argc, int *stack_a)
{
	int	index;
	int	index_2;

	index = argc - stack_size[0];
	index_2 = 0;
	while (index < argc)
	{
		stack_a[index_2] = ft_atoi(argv[index]);
		if (check_for_duplicates(stack_a, index_2) == 0)
			return (0);
		ft_printf("%d:", stack_a[index_2]);
		index++;
		index_2++;
	}
	return (1);
}

//Currently  the main wrapper, I plan to delegate most task to smaller
//wrappers but this is totally fine for testing.
int	main(int argc, char **argv)
{
	int	mode[4];
	int	*stack_a;
	int	*stack_b;
	int	stack_size[2];
	int	opeartions[11];

	ft_bzero(mode, sizeof(mode));
	ft_bzero(stack_size, sizeof(stack_size));
	ft_bzero(opeartions, sizeof(opeartions));
	ft_printf("%d;%d;%d, %d\n", mode[0], mode[1], mode[2], argc);
	get_modes(argv, mode);
	stack_size[0] = argc - 1 - mode[3] - mode[0];
	stack_a = ft_calloc(argc - 1 - mode[3] - mode[0], sizeof(int));
	stack_b = ft_calloc(argc - 1 - mode[3] - mode[0], sizeof(int));
	if (!stack_a || !stack_b || stack_size[0] == 0 || mode[2] == 1)
		return (free(stack_a), free(stack_b), 0);
	if (fill_stack_a(argv, stack_size, argc, stack_a) == 0)
		return (free(stack_a), free(stack_b), 0);
	ft_printf("\n%d;%d;%d, %d %d", mode[0], mode[1], mode[2], stack_size[0], argc);
	ft_printf("\n%d", *stack_a);
}
