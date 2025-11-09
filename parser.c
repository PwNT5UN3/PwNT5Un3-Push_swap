/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:39:52 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/09 13:56:40 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_num(char *value)
{
	if (*value == '-')
		value++;
	if (*value == '\0')
		return (0);
	while (*value >= '0' && *value <= '9')
		value++;
	if (*value != '\0')
		return (0);
	else
		return (1);
}

//This function checks if the current argument is a valid option
int	check_option(char *value)
{
	if (ft_strncmp(value, "--bench", 8) == 0)
		return (1);
	else if (ft_strncmp(value, "--adaptive", 11) == 0)
		return (2);
	else if (ft_strncmp(value, "--simple", 9) == 0)
		return (3);
	else if (ft_strncmp(value, "--medium", 9) == 0)
		return (4);
	else if (ft_strncmp(value, "--complex", 10) == 0)
		return (5);
	else
		return (0);
}

//this oneliner is to save some lines.
//It just sets my "invalid arguments" flag to 1 (true)
void	invalid_arg(t_flag *mode)
{
	mode->invalid_arg = 1;
}

//This function sets the mode flags according to the previosly set selector.
int	parse_selector(int selector, t_flag *mode)
{
	if (selector == 0)
		return (invalid_arg(mode), 0);
	else if (selector == 1)
	{
		if (mode->bench_set == 0)
		{
			mode->bench_set = 1;
			return (1);
		}
		else
			return (invalid_arg(mode), 0);
	}
	else
	{
		if (mode->strategy == 0)
		{
			mode->strategy = selector - 1;
			mode->strat_set = 1;
			return (1);
		}
		else
			return (invalid_arg(mode), 0);
	}
}

//This is my general main parser function.
//It's calling my validator/setter functions.
int	get_modes(char **argv, t_flag *mode)
{
	int	index;
	int	in_options;

	index = 1;
	in_options = 1;
	while (argv[index] != NULL)
	{
		if (ft_strncmp("--", argv[index], 2))
			in_options = 0;
		else
			if (in_options == 0)
				invalid_arg(mode);
		if (in_options)
		{
			if (parse_selector(check_option(argv[index]), mode) == 0)
				return (0);
		}
		else if (is_valid_num(argv[index]) == 0)
			return (invalid_arg(mode), 0);
		index++;
	}
	return (mode->strat_set + mode->bench_set);
}
