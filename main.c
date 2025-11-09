/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:22 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/09 02:47:30 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicates(t_stk *a, int index_2)
{
	int	searchhead;

	searchhead = -1;
	while (++searchhead < index_2)
		if (a->vals[searchhead] == a->vals[index_2])
			return (0);
	return (1);
}

//This function puts all objects into the array stack_a.
int	fill_stack_a(char **argv, int argc, t_stk *a, t_flag *mode)
{
	int	index;

	a->len = argc - get_modes(argv, mode);
	index = get_modes(argv, mode);
	ft_printf("#%d#\n", index);
	ft_printf("%%%d%%%%%d%%\n", mode->bench_set, mode->strat_set);
	a->vals = ft_calloc(a->len, sizeof(int));
	if (!a->vals || a->len == 0 || mode->invalid_arg == 1)
		return (0);
	while (index < argc)
	{
		a->vals[index] = ft_atoi(argv[index]);
		if (check_for_duplicates(a, index) == 0)
			return (0);
		ft_printf("%d:", a->vals[index]);
		index++;
	}
	return (1);
}

//Currently  the main wrapper, I plan to delegate most task to smaller
//wrappers but this is totally fine for testing.
int	main(int argc, char **argv)
{
	t_flag	mode;
	t_stk	a;
	t_stk	b;
	t_stat	stats;

	mode = (t_flag){0};
	stats = (t_stat){0};
	ft_printf("1\n");
	a = (t_stk){.name = 'a', .len = 0, .vals = 0};
	b = (t_stk){.name = 'b', .len = 0, .vals = 0};
	b.vals = ft_calloc(a.len, sizeof(int));
	if (fill_stack_a(argv, argc, &a, &mode) == 0 || !b.vals)
		return (free(a.vals), free(b.vals), 0);
	ft_printf("2\n");
}
