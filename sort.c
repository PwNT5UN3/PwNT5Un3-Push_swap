/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:33:02 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/12 06:36:59 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_stk *a, t_stk *b)
{
	a->sts->disorder = get_disorder(a->vals, a->len);
	if (a->flgs->strategy == SIMPLE)
		simple_sort(a, b);
	else if (a->flgs->strategy == MEDIUM)
		medium_sort(a, b);
	else if (a->flgs->strategy == COMPLEX)
		complex_sort(a, b);
	else
		adaptive_sort(a, b);
	if (a->flgs->bench_set)
		pbench(a->sts);
}
