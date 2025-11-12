/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 03:47:19 by abalcu            #+#    #+#             */
/*   Updated: 2025/11/12 05:11:23 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parr(int *arr, size_t len)
{
	printf("[");
	for (int i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
		if (i < len - 1)
			printf(", ");
	}
	printf("]\n");
}

int	main(void)
{
	int		test[] = {1, 2, 3, 4};
	int		test2[3] = {0};
	t_stat	sts;
	t_flag	flg;
	t_stk	a;
	t_stk	b;

	sts = (t_stat){0};
	flg = (t_flag){0};
	a = (t_stk){.vals = test, .name = 'a', .len = 4, .cap = 4, .sts = &sts,
		.flgs = &flg};
	b = (t_stk){.vals = test2, .name = 'b', .len = 0, .cap = 4, .sts = &sts,
		.flgs = &flg};
	printf("original a: ");
	parr(a.vals, a.len);
	printf("\n");
	s(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	r(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	rr(&a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("\n");
	p(&b, &a);
	printf("a: ");
	parr(a.vals, a.len);
	printf("b: ");
	parr(b.vals, b.len);
	printf("\n");
}

