/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:13:02 by mawelsch          #+#    #+#             */
/*   Updated: 2025/11/08 21:15:45 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

void	get_modes(char **argv, int *mode);
int		parse_selector(int selector, int *mode);
void	invalid_arg(int *mode);
int		check_option(char *value, int in_options);
int		fill_stack_a(char **argv, int *stack_size, int argc, int *stack_a);
int		check_for_duplicates(int *stack_a, int index_2);

//The methods
void	sa(int *stack_a, int *stack_size, int *operations);
void	sb(int *stack_b, int *stack_size, int *operations);
void	ss(int *stack_a, int *stack_b, int *stack_size, int *operations);
void	pa(int *stack_a, int *stack_b, int *stack_size, int *operations);
void	pb(int *stack_a, int *stack_b, int *stack_size, int *operations);
void	ra(int *stack_a, int *stack_size, int *operations);
void	rb(int *stack_b, int *stack_size, int *operations);
void	rr(int *stack_a, int *stack_b, int *stack_size, int *operations);
void	rra(int *stack_a, int *stack_size, int *operations);
void	rrb(int *stack_b, int *stack_size, int *operations);
void	rrr(int *stack_a, int *stack_b, int *stack_size, int *operations);

#endif //PUSH_SWAP_H