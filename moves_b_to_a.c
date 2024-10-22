/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:19:07 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/22 15:05:51 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	b_to_a_updown(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a)
{
	int		size_a;
	int		size_b;
	float	ratio_src;
	float	ratio_dest;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	ratio_src = (float)pos_in_a /(float)size_a;
	ratio_dest = (float)pos_in_b /(float)size_b;
	while (ratio_src <= 0.5 && pos_in_a-- != 0)
		ra(a);
	while (ratio_src > 0.5 && pos_in_a++ < size_a)
		rra(a);
	while (ratio_dest <= 0.5 && pos_in_b-- != 0)
		rb(b);
	while (ratio_dest > 0.5 && pos_in_b++ < size_b)
	{
		// ft_printf("move_updown: \n");
		rrb(b);
	}
}

void	b_to_a_up(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a)
{
	// ft_printf("dest index: %d\n", pos_in_b);
	while (pos_in_a > 0 && pos_in_b > 0)
	{
		// ft_printf("move_up: \n");
		rr(a, b);
		pos_in_a--;
		pos_in_b--;
	}
	while (pos_in_a > 0)
	{
		// ft_printf("move_up: \n");
		ra(a);
		pos_in_a--;
	}
	while (pos_in_b > 0)
	{
	// ft_printf("move_up: \n");
		rb(b);
		pos_in_b--;
	}
}

void	b_to_a_down(t_stack **b, t_stack **a, int pos_in_b, int pos_in_a)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	while (pos_in_a <= size_a - 1 && pos_in_b <= size_b - 1)
	{
		// ft_printf("move_down: \n");
		rrr(a, b);
		pos_in_a++;
		pos_in_b++;
	}
	while (pos_in_a <= size_a - 1)
	{
		// ft_printf("move_down: \n");
		rra(a);
		pos_in_a++;
	}
	while (pos_in_b <= size_b - 1)
	{
		// ft_printf("move_down: \n");
		rrb(b);
		pos_in_b++;
	}
}

void	b_to_a_moves(t_stack **src, t_stack **dest, t_stack *node, char s_flag)
{
	int	src_i;
	int dest_i;
	int	size_src;
	int	size_dest;

	src_i = find_index_in_src(node->nbr, src);
	dest_i = find_index_in_dest(node->nbr, dest, s_flag);
	size_src = stack_size(*src);
	size_dest = stack_size(*dest);

	// ft_printf("\n%c\n", best_move_char(src, dest, size_a, size_b, node->nbr));
	if (best_move_char(src_i, dest_i, size_src, size_dest) == 'u')
		b_to_a_up(src, dest, src_i, dest_i);
	else if (best_move_char(src_i, dest_i, size_src, size_dest) == 'd')
		b_to_a_down(src, dest, src_i, dest_i);
	else
		b_to_a_updown(src, dest, src_i, dest_i);
}