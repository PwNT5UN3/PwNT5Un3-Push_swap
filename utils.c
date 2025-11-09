/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:18:48 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/09 01:29:46 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_get_disorder(int *stack, int size)
{
	unsigned int	mistakes;
	unsigned int	pairs;
	int				i;
	int				j;

	i = 0;
	pairs = 0;
	mistakes = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			pairs++;
			if (stack[i] > stack[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / pairs);
}

int	ft_is_num(char const *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_bench(t_flag *flags, char const *arg)
{
	if (ft_memcmp(arg, "--bench", 8) == 0)
	{
		flags->bench_set++;
		return (1);
	}
	return (0);
}

int	ft_parse_strat(t_flag *flags, char const *arg)
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

int	ft_parse_flag(t_flag *flags, int *pos, int argc, char const *argv[])
{
	while (*pos < argc && !ft_is_num(argv[*pos]))
	{
		flags->valid_flag += ft_parse_strat(flags, argv[*pos]);
		flags->valid_flag += ft_parse_bench(flags, argv[*pos]);
		if (!flags->valid_flag)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		if (flags->strat_set > 1 || flags->bench_set > 1)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		(*pos)++;
	}
	return (1);
}

int	ft_parse_numargs(t_stk *stks, int *pos, int argc, char const *argv[])
{
	while (*pos < argc)
	{
		if (ft_is_num(argv[*pos]))
		{
			ft_printf("arg %s\n", argv[*pos]); // modify to add the numbers latter
			stks->count++;
		}
		else
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (0);
		}
		(*pos)++;
	}
	return (1);
}

int main(int argc, char const *argv[])
{
	int		pos;
	t_flag	flags;
	t_stk	stk_a;
	t_stk	stk_b;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	pos = 1;
	flags = (t_flag){0};
	stk_a = (t_stk){0};
	stk_b = (t_stk){0};
	if (!ft_parse_flag(&flags, &pos, argc, argv))
		return (1);
	if (!ft_parse_numargs(&stks, &pos, argc, argv))
	{
		ft_lstclear(&stks.stk_a, free);
		return (1);
	}
	if (!stks.count)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (1);
	}
	ft_printf("Pass");
	return (0);
}
