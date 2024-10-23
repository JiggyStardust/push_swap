/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:27:38 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/23 18:34:04 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->nbr;
	b = (*stack_a)->next->nbr;
	c = (*stack_a)->next->next->nbr;
	if (a > b && b > c) // 3 2 1
	{	
		ra(stack_a); // 2 1 3
		sa(stack_a); //1 2 3
	}
	else if (a > c && c > b) // 3 1 2
		ra(stack_a); // 1 2 3
	else if (a < c && b > c)// 1 3 2 
	{
		rra(stack_a); // 2 1 3
		sa(stack_a); // 1 2 3
	}
	else if (a > b && c > a) // 2 1 3
		sa(stack_a);  // 1 2 3
	else if (a > c && b > a) // 2 3 1
		rra(stack_a); // 1 2 3
}

int		already_sorted(t_stack *stack)
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

int		find_minimum(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	int		node;
	
	temp = *stack;
	min = min_in_stack(stack);
	node = 0;
	while (temp->next != *stack && temp->nbr != min)
	{
		temp = temp->next;
		node++;
	}
	return (node);
}

void	min_up(t_stack **stack)
{
	int		min_node;
	float	ratio;
	int		size;
	
	min_node = find_minimum(stack);
	size = stack_size(*stack);
	ratio = (float)min_node/(float)size;
	if (ratio <= 0.5)
	{
		while (min_node != 0)
		{
			ra(stack);
			min_node--;
		}
	}
	else if (ratio > 0.5)
	{
		while (min_node <= size - 1)
		{
			rra(stack);
			min_node++;
		}
	}
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
