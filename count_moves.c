/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:44 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/10 14:02:02 by sniemela         ###   ########.fr       */
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

int		mixed_moves(int moves_up_a, int moves_up_b, int moves_down_a, int moves_down_b)
{
	int	mixed_a_up;
	int mixed_a_down;

	mixed_a_up = moves_up_a + moves_down_b;
	mixed_a_down = moves_down_a + moves_up_b;
	if (mixed_a_up <= mixed_a_down)
		return (mixed_a_up);
	else
		return (mixed_a_down);
}

char	best_move_char(int src_i, int dest_i, int src_size, int dest_size)
{
	int	moves_up;
	int	moves_down;
	int mixed_moves;

	moves_up = moves_up(src_i + dest_i);
	moves_down = moves_down(src_size - src_i, dest_size - dest_i);
	mixed_moves = mixed_moves(src_i, dest_i, src_size - src_i, dest_size - dest_i);
	
	if (moves_down < moves_up && moves_down < mixed_moves)
		return ("down");
	else if (moves_up < moves_down && moves_up < mixed_moves)
		return ("up");
	else
		return ("mixed");
}

int		best_move_int(int src_i, int dest_i, int src_size, int dest_size)
{
	int	moves_up;
	int	moves_down;
	int mixed_moves;

	moves_up = moves_up(src_i + dest_i);
	moves_down = moves_down(src_size - src_i, dest_size - dest_i);
	mixed_moves = mixed_moves(src_i, dest_i, src_size - src_i, dest_size - dest_i);
	
	if (moves_down < moves_up && moves_down < mixed_moves)
		return (moves_down);
	else if (moves_up < moves_down && moves_up < mixed_moves)
		return (moves_up);
	else
		return (mixed_moves);
}

char	calculate_moves(t_stack **stack_a, t_stack **stack_b, int nbr1, int nbr2, int *moves)
{
	int	src_i; 
	int dest_i;
	
	src_i = find_index_in_stack(nbr1, stack_a);
	dest_i = find_index_in_stack(nbr2, stack_b);
	moves = best_move_int(src_i, dest_i, stack_size(*stack_a), stack_size(*stack_b));
	return (best_moves_char(src_i, dest_i, stack_size(*stack_a), stack_size(*stack_b)));
}




