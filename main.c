/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:22 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 18:06:19 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("%d;%d;%d, %d %d\n", mode[0], mode[1], mode[2], stack_size[0], argc);
	fill_stack_a(argv, stack_size, argc, stack_a);
	ft_printf("\n%d", *stack_a);
}
