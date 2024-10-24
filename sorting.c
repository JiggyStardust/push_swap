/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:37:56 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 15:36:52 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	already_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next != stack)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b > c)
	{	
		ra(stack_a);
		sa(stack_a);
	}
	else if (a > c && c > b)
		ra(stack_a);
	else if (a < c && b > c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && c > a)
		sa(stack_a);
	else if (a > c && b > a)
		rra(stack_a);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size < 3)
		sa(stack_a);
	else if (size > 3)
	{
		while (size > 3 && !already_sorted(*stack_a))
		{
			min_up(stack_a);
			pb(stack_a, stack_b);
			size--;
		}
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = NULL;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 3)
	{
		node = cheapest_node(stack_a, stack_b, 'b');
		a_to_b_moves(stack_a, stack_b, node, 'b');
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
	{
		node = cheapest_node(stack_b, stack_a, 'a');
		b_to_a_moves(stack_b, stack_a, node, 'a');
		pa(stack_a, stack_b);
	}
	while (find_minimum(stack_a) != 0)
		min_up(stack_a);
}
