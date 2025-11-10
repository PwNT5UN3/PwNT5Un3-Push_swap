/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:59:26 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/10 04:18:29 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_bench(t_flag *flags, char const *arg)
{
	if (ft_memcmp(arg, "--bench", 8) == 0)
	{
		flags->bench_set++;
		return (1);
	}
	return (0);
}

int	parse_strat(t_flag *flags, char const *arg)
{
	if (ft_memcmp(arg, "--simple", 9) == 0)
		flags->strategy = SIMPLE;
	else if (ft_memcmp(arg, "--medium", 9) == 0)
		flags->strategy = MEDIUM;
	else if (ft_memcmp(arg, "--complex", 10) == 0)
		flags->strategy = COMPLEX;
	else if (ft_memcmp(arg, "--adaptive", 11) == 0)
		flags->strategy = ADAPTIVE;
	else
		return (0);
	flags->strat_set++;
	return (1);
}

int	parse_flag(t_flag *flags, int *pos, int argc, char const *argv[])
{
	while (*pos < argc && !is_num(argv[*pos]) && *argv[*pos])
	{
		flags->valid_flag += parse_strat(flags, argv[*pos]);
		flags->valid_flag += parse_bench(flags, argv[*pos]);
		if (!flags->valid_flag)
			return (perror(), 0);
		if (flags->strat_set > 1 || flags->bench_set > 1)
			return (perror(), 0);
		(*pos)++;
	}
	return (1);
}

int	parse_numargs(t_stk *stk, int *pos, int argc, char const *argv[])
{
	int	index;

	index = 0;
	stk->val = (int *)ft_calloc(argc - *pos, sizeof(int));
	if (!stk->val)
		return (0);
	while (*pos < argc)
	{
		if (is_num(argv[*pos]))
		{
			stk->val[index] = ft_atoi(argv[*pos]);
			stk->len++;
			index++;
		}
		else
			return (free(stk->val), perror(), 0);
		(*pos)++;
	}
	if (!stk->len)
		return (free(stk->val), perror(), 0);
	return (1);
}

int	main(int argc, char const *argv[])
{
	int		pos;
	t_flag	flags;
	t_stk	a;
	t_stk	b;

	if (argc < 2)
		return (perror(), 1);
	pos = 1;
	flags = (t_flag){0};
	a = (t_stk){.name = 'a', .len = 0, .val = NULL};
	b = (t_stk){.name = 'b', .len = 0, .val = NULL};
	if (!parse_flag(&flags, &pos, argc, argv))
		return (1);
	if (!parse_numargs(&a, &pos, argc, argv))
		return (1);
	b.val = (int *)ft_calloc(a.len, sizeof(int));
	if (!b.val)
		return (perror(), 1);
	ft_printf("Pass\n");
	return (free(a.val), free(b.val), 0);
}
