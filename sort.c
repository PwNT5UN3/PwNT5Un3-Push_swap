/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:33:02 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/12 04:42:11 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_stk *a, t_stk *b)
{
	if (a->sts->strategy == SIMPLE)
		simple_sort(a);
	else if (a->sts->strategy == MEDIUM)
		medium_sort(a, b);
	else if (a->sts->strategy == COMPLEX)
		complex_sort(a, b);
	else
		adaptive_sort(a, b);
	if (a->flgs->bench_set)
		pbench(a->sts);
}
