/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:14:36 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/22 15:04:36 by sniemela         ###   ########.fr       */
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
char	best_move_char(int src_i, int dest_i, int s_size, int d_size);
int		best_move_int(int src_i, int dest_i, int src_size, int dest_size);
int		ft_mix(int m_up_a, int m_up_b, int m_down_a, int m_down_b);
int		ft_moves_down(int moves_down_a, int moves_down_b);
int		ft_moves_up(int moves_up_a, int moves_up_b);
int		calculate_moves(t_stack **stack_a, t_stack **stack_b, int nbr, char stack_f);
t_stack	*cheapest_node(t_stack **stack_a, t_stack **stack_b, char stack_f);
int		find_index_in_dest(int n, t_stack **stack, char stack_f);
int		find_index_in_src(int nbr, t_stack **stack);
int		find_index_in_a(int n, t_stack **stack);
int		find_index_in_b(int n, t_stack **stack);
int		find_minimum(t_stack **stack);
int		find_maximum(t_stack **stack);
int		max_in_stack(t_stack **stack);
int		min_in_stack(t_stack **stack);
// void	max_up(t_stack **stack);
void	min_up(t_stack **stack);

// Executing moves from stack a to stack b

void	a_to_b_moves(t_stack **src, t_stack **dest, t_stack *node, char s_flag);
void	a_to_b_down(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b);
void	a_to_b_up(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b);
void 	a_to_b_updown(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b);

// Executing moves from stack b to stack a

void	b_to_a_moves(t_stack **src, t_stack **dest, t_stack *node, char s_flag);
void	b_to_a_down(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a);
void	b_to_a_up(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a);
void 	b_to_a_updown(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a);

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