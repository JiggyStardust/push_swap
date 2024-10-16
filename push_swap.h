/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:36 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/18 14:41:33 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# define MAX_INT 2147483647

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
int		stack_size(t_stack *lst);

//	calculating and inspecting stacks and moves

int		already_sorted(t_stack *stack);
char	best_move_char(t_stack **a, t_stack **b, int s_size, int d_size, int n);
int		best_move_int(int src_i, int dest_i, int src_size, int dest_size);
int		calc_mixed_moves(int m_up_a, int m_up_b, int m_down_a, int m_down_b);
int		calculate_moves(t_stack **stack_a, t_stack **stack_b, int nbr);
int		calc_moves_up(int moves_up_a, int moves_up_b);
int		calc_moves_down(int moves_down_a, int moves_down_b);
t_stack	*cheapest_node(t_stack **stack_a, t_stack **stack_b);
int		find_index_in_src(int nbr, t_stack **stack);
int		find_index_in_dest(int nbr, t_stack **stack);
int		find_minimum(t_stack **stack);
int		find_maximum(t_stack **stack);  	// is it really needed?
int		max_in_stack(t_stack **stack);
int		min_in_stack(t_stack **stack);
// void	max_up(t_stack **stack);
void	min_up(t_stack **stack);
int		moves_down(int moves_down_a, int moves_down_b);
int		moves_up(int moves_up_a, int moves_up_b);

// Helpers for sorting

void	execute_moves(t_stack **src, t_stack **dest, t_stack *node);
void	move_down(t_stack **a, t_stack **b, t_stack *node);
void	move_up(t_stack **stack_a, t_stack **stack_b, t_stack *node);
void 	move_updown(t_stack **a, t_stack **b, t_stack *node, int s_a, int s_b);

// Sorting algorhithms
void	sort_three(t_stack **stack_a);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

// Pushing

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **dest_stack, t_stack *src_node);

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