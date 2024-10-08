/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:50:25 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/08 15:54:28 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_maximum(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		node;
	
	temp = *stack;
	max = (*stack)->nbr;
	node = 0;
	while (temp->next != *stack)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
	}
	temp = *stack;
	while (max != temp->nbr)
	{
		temp = temp->next;
		node++;
	}
	return (node);
}

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int		max_node_a;
	int		max_node_b;
	int		size_a;
	int		size_b;
	float	ratio_a;
	float	ratio_b;

	max_node_a = find_maximum(stack_a);
	max_node_b = find_maximum(stack_b);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	ratio_a = (float)max_node_a/(float)size_a;
	ratio_b = (float)max_node_b/(float)size_b;
	if (max_node_b == 1)
		sb(stack_b);
	else if (max_node_a == 1)
		sa(stack_a);
	else if (max_node_a == 1 && max_node_b == 1)
		ss(stack_a, stack_b);
	else if (ratio_a <= 0.5 && ratio_b <= 0.5) // or should ratio == 0.5 be handled in own function?
		rr(stack_a, stack_b);
	else if (ratio_a > 0.5 && ratio_b > 0.5)
		rrr(stack_a, stack_b);
	else if (ratio_a <= 0.5 && ratio_b > 0.5)
	{
		ra(stack_a);
		rb(stack_b);
	}
	else if (ratio_a > 0.5 && ratio_b <= 0.5)
	{
		rra(stack_b);
		rb(stack_b);
	}
}

void	max_up_b(t_stack **stack, int size)
{
	int		max_node;
	float	ratio;

	max_node = find_maximum(stack);
	ratio = (float)max_node/(float)size;
	if (max_node == 1)
		sb(stack);
	else if (ratio) // or should ratio == 0.5 be handled in own function?
		rb(stack);
	else if (ratio > 0.5)
		rrb(stack);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 0)
	{
		if ((*stack_a)->nbr > (*stack_b)->nbr && find_maximum(stack_b) == 0)
			pb(stack_a, stack_b);
		else if ((*stack_a)->nbr > (*stack_b)->nbr)
			max_up_b(stack_b, stack_size(*stack_b));
		else
			cheapest_move(stack_a, stack_b);
	}
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
}