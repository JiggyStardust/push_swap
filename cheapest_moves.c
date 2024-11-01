/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:49:32 by sniemela          #+#    #+#             */
/*   Updated: 2024/11/01 13:56:26 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheapest_node(t_stack **src, t_stack **dest, char STACK_F)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_moves;
	int		moves;

	current = *src;
	cheapest = NULL;
	min_moves = INT_MAX;
	if (current->next == *src)
		return (current);
	while (current->next != *src)
	{
		moves = calculate_moves(src, dest, current->nbr, STACK_F);
		if (moves < min_moves)
		{
			cheapest = current;
			min_moves = moves;
		}
		current = current->next;
	}
	return (cheapest);
}

char	best_move_char(int src_i, int dest_i, int s_size, int d_size)
{
	int	moves_up;
	int	moves_down;
	int	mixed_moves;

	moves_up = ft_moves_up(src_i, dest_i);
	moves_down = ft_moves_down(s_size - src_i, d_size - dest_i);
	mixed_moves = ft_mix(src_i, dest_i, s_size - src_i, d_size - dest_i);
	if (moves_down < moves_up && moves_down < mixed_moves)
		return ('d');
	else if (moves_up < moves_down && moves_up < mixed_moves)
		return ('u');
	else
		return ('m');
}
