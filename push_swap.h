/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:36 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/07 13:43:00 by sniemela         ###   ########.fr       */
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

// temporary tools for inspecting the program

void	print_stack(t_stack *stack);

// handling, allocating and deallocating stacks

void	add_to_stack(t_stack **stack, int nbr);
void	free_node(t_stack **stack);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **dest_stack, t_stack *src_node);
int		stack_size(t_stack *lst);

//	calculating and inspecting stacks and moves

int		already_sorted(t_stack *stack);
int		find_minimum(t_stack **stack);
void	min_up(t_stack **stack, int size);

// Sorting algorhithms
void	sort_three(t_stack **stack_a);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack);

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