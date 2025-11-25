/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:15:31 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/25 21:36:18 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stk *a, t_stk *b)
{
	if (a->sts->disorder < 0.2)
		simple_sort(a, b);
	else if (a->sts->disorder < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
