/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:17:44 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/22 14:58:58 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_moves_up(int moves_up_a, int moves_up_b)
{
	int	moves_up;

	if (moves_up_a >= moves_up_b)
		moves_up = moves_up_b + (moves_up_a - moves_up_b);
	else
		moves_up = moves_up_a + (moves_up_b - moves_up_a);
	return (moves_up);
}

int		ft_moves_down(int moves_down_a, int moves_down_b)
{
	int	moves_down;
	
	if (moves_down_a >= moves_down_b)
		moves_down = moves_down_b + (moves_down_a - moves_down_b);
	else
		moves_down = moves_down_a + (moves_down_b - moves_down_a);
	return (moves_down);
}

int		ft_mix(int m_up_a, int m_up_b, int m_down_a, int m_down_b)
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

	moves_up = ft_moves_up(src_i, dest_i);
	moves_down = ft_moves_down(src_size - src_i, dest_size - dest_i);
	mixed = ft_mix(src_i, dest_i, src_size - src_i, dest_size - dest_i);
	
	if (moves_down < moves_up && moves_down < mixed)
		return (moves_down);
	else if (moves_up < moves_down && moves_up < mixed)
		return (moves_up);
	else
		return (mixed);
}

int		calculate_moves(t_stack **src, t_stack **dest, int nbr, char STACK_F)
{
	int	src_i;
	int dest_i;
	int	moves;
	int	size_s;
	int	size_d;
	
	src_i = find_index_in_src(nbr, src);
	dest_i = find_index_in_dest(nbr, dest, STACK_F);
	size_s = stack_size(*src);
	size_d = stack_size(*dest);
	moves = best_move_int(src_i, dest_i, size_s, size_d);
	return (moves);
}