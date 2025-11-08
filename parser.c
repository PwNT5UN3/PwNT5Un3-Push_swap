/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:39:52 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 20:58:41 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//This function checks if the current argument is a valid option
int	check_option(char *value, int in_options)
{
	if (in_options)
	{
		if (ft_strncmp(value, "--bench", 8) == 0)
			return (1);
		else if (ft_strncmp(value, "--simple", 9) == 0)
			return (2);
		else if (ft_strncmp(value, "--medium", 9) == 0)
			return (3);
		else if (ft_strncmp(value, "--complex", 10) == 0)
			return (4);
		else if (ft_strncmp(value, "--adaptive", 11) == 0)
			return (5);
		else
			return (0);
	}
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

//this oneliner is to save some lines.
//It just sets my "invalid arguments" flag to 1 (true)
void	invalid_arg(int *mode)
{
	mode[2] = 1;
}

//This function sets the mode flags according to the previosly set selector.
int	parse_selector(int selector, int *mode)
{
	if (selector == 0)
		return (invalid_arg(mode), 0);
	else if (selector == 1)
	{
		if (mode[0] == 0)
		{
			mode[0] = 1;
			return (1);
		}
		else
			return (invalid_arg(mode), 0);
	}
	else
	{
		if (mode[1] == 0)
		{
			mode[1] = selector - 1;
			mode[3] = 1;
			return (1);
		}
		else
			return (invalid_arg(mode), 0);
	}
}

//This is my general main parser function.
//It's calling my validator/setter functions.
void	get_modes(char **argv, int *mode)
{
	int	index;
	int	in_options;
	int	selector;

	index = 1;
	in_options = 1;
	while (argv[index] != NULL)
	{
		if (ft_strncmp("--", argv[index], 2))
			in_options = 0;
		else
			if (in_options == 0)
				mode[2] = 0;
		selector = check_option(argv[index], in_options);
		if (in_options)
		{
			if (parse_selector(selector, mode) == 0)
				return ;
		}
		else if (selector == 0)
			return (invalid_arg(mode));
		index++;
	}
	if (mode[1] == 0)
		mode[1] = 4;
}

//This function puts all objects into the array stack_a.
void	fill_stack_a(char **argv, int *stack_size, int argc, int *stack_a)
{
	int	index;
	int	index_2;

	index = argc - stack_size[0];
	index_2 = 0;
	while (index < argc)
	{
		stack_a[index_2] = ft_atoi(argv[index]);
		ft_printf("%d:", stack_a[index_2]);
		index++;
		index_2++;
	}
}
