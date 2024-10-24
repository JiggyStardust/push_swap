/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:13 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 12:29:35 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_updown(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b)
{
	int		size_a;
	int		size_b;
	float	ratio_src;
	float	ratio_dest;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	ratio_src = (float)pos_in_a / (float)size_a;
	ratio_dest = (float)pos_in_b / (float)size_b;
	while (ratio_src <= 0.5 && pos_in_a-- != 0)
		ra(a);
	while (ratio_src > 0.5 && pos_in_a++ < size_a)
		rra(a);
	while (ratio_dest <= 0.5 && pos_in_b-- != 0)
		rb(b);
	while (ratio_dest > 0.5 && pos_in_b++ < size_b)
		rrb(b);
}

void	a_to_b_up(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b)
{
	while (pos_in_a > 0 && pos_in_b > 0)
	{
		rr(a, b);
		pos_in_a--;
		pos_in_b--;
	}
	while (pos_in_a > 0)
	{
		ra(a);
		pos_in_a--;
	}
	while (pos_in_b > 0)
	{
		rb(b);
		pos_in_b--;
	}
}

void	a_to_b_down(t_stack **a, t_stack **b, int pos_in_a, int pos_in_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	while (pos_in_a <= size_a - 1 && pos_in_b <= size_b - 1)
	{
		rrr(a, b);
		pos_in_a++;
		pos_in_b++;
	}
	while (pos_in_a <= size_a - 1)
	{
		rra(a);
		pos_in_a++;
	}
	while (pos_in_b <= size_b - 1)
	{
		rrb(b);
		pos_in_b++;
	}
}

void	a_to_b_moves(t_stack **src, t_stack **dest, t_stack *node, char s_flag)
{
	int	src_i;
	int	dest_i;
	int	size_src;
	int	size_dest;

	src_i = find_index_in_src(node->nbr, src);
	dest_i = find_index_in_dest(node->nbr, dest, s_flag);
	size_src = stack_size(*src);
	size_dest = stack_size(*dest);
	if (best_move_char(src_i, dest_i, size_src, size_dest) == 'u')
		a_to_b_up(src, dest, src_i, dest_i);
	else if (best_move_char(src_i, dest_i, size_src, size_dest) == 'd')
		a_to_b_down(src, dest, src_i, dest_i);
	else
		a_to_b_updown(src, dest, src_i, dest_i);
}
