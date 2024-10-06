/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:36 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/06 13:01:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"


typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
} t_stack;

// handling and allocating stacks

void	add_to_stack(t_stack **stack, int nbr);


int		already_sorted(t_stack *stack);

// Sorting algorhithms
void	sort_three(t_stack **stack_a);
void	sort_small(t_stack **stack);

// Rotating functions

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Swapping functions

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);

#endif