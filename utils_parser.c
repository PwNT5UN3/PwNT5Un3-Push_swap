/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:39:52 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/25 22:59:32 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains(int *arr, int nbr, size_t len)
{
	if (!len || !arr)
		return (0);
	while (len--)
	{
		if (*arr == nbr && len != 0)
			return (1);
		arr++;
	}
	return (0);
}

int	parse_numargs(t_stk *stk, int *pos, int argc, char const *argv[])
{
	stk->sts->strategy = stk->flgs->strategy;
	while (*pos < argc)
	{
		if (!parse_args_str(stk, argv[*pos]))
			return (free(stk->vals), perror(), 0);
		(*pos)++;
	}
	if (!stk->len)
		return (free(stk->vals), perror(), 0);
	return (1);
}
