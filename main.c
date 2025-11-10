/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:43:22 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/10 18:26:36 by mawelsch         ###   ########.fr       */
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
	int	flag_count;

	flag_count = get_modes(argv, mode);
	a->len = argc - flag_count - 1;
	index = flag_count + 1;
	a->vals = ft_calloc(a->len, sizeof(int));
	if (a->vals == NULL || a->len == 0 || mode->invalid_arg == 1)
		return (0);
	while (index < argc)
	{
		a->vals[index - flag_count - 1] = ft_atoi(argv[index]);
		if (check_for_duplicates(a, index - flag_count - 1) == 0)
			return (0);
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
	int		fill_success;

	fill_success = 0;
	mode = (t_flag){0};
	stats = (t_stat){0};
	ft_printf("1\n");
	a = (t_stk){.name = 'a', .len = 0, .vals = 0};
	b = (t_stk){.name = 'b', .len = 0, .vals = 0};
	fill_success = fill_stack_a(argv, argc, &a, &mode);
	b.vals = ft_calloc(a.len, sizeof(int));
	if (fill_success == 0 || !b.vals)
		return (free(a.vals), free(b.vals), 0);
	ft_printf("\n2\n");
}
