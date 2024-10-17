/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:50:25 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/17 16:19:21 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		find_maximum(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		node;
	int		index;
	
	temp = *stack;
	max = (*stack)->nbr;
	node = 0;
	index = 0;
	while (temp->next != *stack)
	{
		if (max < temp->nbr)
		{
			max = temp->nbr;
			index = node;
		}
		temp = temp->next;
		node++;
	}
	if (max < temp->nbr)
	{
		max = temp->nbr;
		index = node;
	}
	return (index);
}

void	max_up(t_stack **stack)
{
	int		max_node;
	int		size;
	float	ratio;

//	printf("size: %d\n", size);
	max_node = find_maximum(stack);
	size = stack_size(stack);
//	printf("max_node: %d\n", max_node);
	ratio = (float)max_node/(float)size;
//	printf("ratio: %f.2\n", ratio);
	if (ratio <= 0.5) // or should ratio == 0.5 be handled in own function?
		rb(stack);
	else if (ratio > 0.5)
		rrb(stack);
}

int		find_index_in_a(int nbr, t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (nbr != temp->nbr)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int		find_index_in_b(int nbr, t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (nbr < temp->next->nbr)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = NULL;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (find_maximum(stack_b) != 0)
		sb(stack_b);
	while (stack_size(*stack_a) > 3)
	{
		node = cheapest_node(stack_a, stack_b);
		execute_moves(stack_a, stack_b, node);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (find_maximum(stack_b) != 0)
		max_up(stack_b);
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
	while (find_minimum(stack_a) != 0)
		min_up(stack_a);
}
