/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalcu <abalcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:13:02 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/12 04:38:52 by abalcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "utils/push_swap_utils.h"

void	ps_sort(t_stk *a, t_stk *b);

void	simple_sort(t_stk *stk);
void	medium_sort(t_stk *a, t_stk *b);
void	complex_sort(t_stk *a, t_stk *b);
void	adaptive_sort(t_stk *a, t_stk *b);

#endif // PUSH_SWAP_H
