/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:44 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/17 16:18:48 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		moves_up(int moves_up_a, int moves_up_b)
{
	int	moves_up;
	int moves_down;

	if (moves_up_a >= moves_up_b)
		moves_up = moves_up_b + (moves_up_a - moves_up_b);
	else
		moves_up = moves_up_a + (moves_up_b - moves_up_a);
	return (moves_up);
}

int		moves_down(int moves_down_a, int moves_down_b)
{
	if (moves_down_a >= moves_down_b)
		moves_down = moves_down_b + (moves_down_a - moves_down_b);
	else
		moves_down = moves_down_a + (moves_down_b - moves_down_a);
}

int		mixed_moves(int m_up_a, int m_up_b, int m_down_a, int m_down_b)
{
	int	mixed_a_up;
	int mixed_a_down;

	mixed_a_up = m_up_a + m_down_b;
	mixed_a_down = m_down_a + m_up_b;
	if (mixed_a_up <= mixed_a_down)
		return (mixed_a_up);
	else
		return (mixed_a_down);
}

int		best_move_int(int src_i, int dest_i, int src_size, int dest_size)
{
	int	moves_up;
	int	moves_down;
	int mixed;

	moves_up = moves_up(src_i + dest_i);
	moves_down = moves_down(src_size - src_i, dest_size - dest_i);
	mixed = mixed_moves(src_i, dest_i, src_size - src_i, dest_size - dest_i);
	
	if (moves_down < moves_up && moves_down < mixed)
		return (moves_down);
	else if (moves_up < moves_down && moves_up < mixed)
		return (moves_up);
	else
		return (mixed);
}

int		calculate_moves(t_stack **stack_a, t_stack **stack_b, int nbr)
{
	int	src_i;
	int dest_i;
	int	moves;
	int	size_a;
	int	size_b;
	
	src_i = find_index_in_a(nbr, stack_a);
	dest_i = find_index_in_b(nbr, stack_b);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);;
	moves = best_move_int(src_i, dest_i, size_a, size_b);
	return (moves);
}

t_stack	*cheapest_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_moves;
	int		moves;

	current = *stack_a;
	cheapest = NULL;
	min_moves = MAX_INT;
	while (current->next != *stack_a)
	{
		moves = calculate_moves(stack_a, stack_b, current->nbr);
		if (moves < min_moves)
		{
			cheapest = current;
			min_moves = moves;
		}
		current = current->next;
	}
	return (cheapest);
}

char	best_move_char(t_stack **a, t_stack **b, int s_size, int d_size, int n)
{
	int	moves_up;
	int	moves_down;
	int mixed_moves;
	int	src_i;
	int	dest_i;

	src_i = find_index_in_a(n, a);
	dest_i = find_index_in_b(n, b);
	moves_up = moves_up(src_i + dest_i);
	moves_down = moves_down(s_size - src_i, d_size - dest_i);
	mixed_moves = mixed_moves(src_i, dest_i, s_size - src_i, d_size - dest_i);
	
	if (moves_down < moves_up && moves_down < mixed_moves)
		return ("down");
	else if (moves_up < moves_down && moves_up < mixed_moves)
		return ("up");
	else
		return ("mixed");
}
void	move_down(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	pos_in_a;
	int	pos_in_b;

	pos_in_a = find_index_in_a(node->nbr, stack_a);
	pos_in_b = find_index_in_b(node->nbr, stack_b);
	while (pos_in_a > 0 && pos_in_b > 0)
	{
		rrr(stack_a, stack_b);
		pos_in_a--;
		pos_in_b--;
	}
	while (pos_in_a > 0)
		rra(stack_a);
	while (pos_in_b > 0)
		rrb(stack_b);
}

void	move_up(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	pos_in_a;
	int	pos_in_b;

	pos_in_a = find_index_in_a(node->nbr, stack_a);
	pos_in_b = find_index_in_b(node->nbr, stack_b);
	while (pos_in_a > 0 && pos_in_b > 0)
	{
		rr(stack_a, stack_b);
		pos_in_a--;
		pos_in_b--;
	}
	while (pos_in_a > 0)
		ra(stack_a);
	while (pos_in_b > 0)
		rb(stack_b);
}

void 	move_updown(t_stack **a, t_stack **b, t_stack *node, int s_a, int s_b)
{
	int		pos_in_a;
	int		pos_in_b;
	float	ratio_a;
	float	ratio_b;

	pos_in_a = find_index_in_a(node->nbr, a);
	pos_in_b = find_index_in_b(node->nbr, b);
	ratio_a = (float)pos_in_a /(float)s_a;
	ratio_b = (float)pos_in_b /(float)s_b;
	while (ratio_a <= 0.5 && ratio_a != 0)
		ra(a);
	while (ratio_a > 0.5 && ratio_a != 1)
		rra(a);
	while (ratio_b <= 0.5 && ratio_b != 0)
		rb(b);
	while (ratio_b > 0.5 && ratio_b != 1)
		rrb(b);
}

void	execute_moves(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	if (best_move_char(stack_a, stack_b, size_a, size_b, node->nbr) == "up")
		move_up(stack_a, stack_b, node)
	else if (best_move_char(size_a, size_b, node->nbr) == "down")
		move_down(stack_a, stack_b, node);
	else
		move_updown(stack_a, stack_b, node, size_a, size_b);
}