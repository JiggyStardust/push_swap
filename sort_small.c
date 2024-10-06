/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:27:38 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/06 12:57:20 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		print_stack(*stack_a);
		ra(stack_a); // 2 1 3
		print_stack(*stack_a);
		sa(stack_a); //1 2 3
		print_stack(*stack_a);
	}
	else if (a > c && c > b) // 3 1 2
	{
		print_stack(*stack_a);
		ra(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
	else if (a < c && b > c)// 1 3 2 
	{
		print_stack(*stack_a);
		rra(stack_a); // 2 1 3
		print_stack(*stack_a);
		sa(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
	else if (a > b && c > a) // 2 1 3
	{
		print_stack(*stack_a);	
		sa(stack_a);  // 1 2 3
		print_stack(*stack_a);
	}
	else if (a > c && b > a) // 2 3 1
	{
		print_stack(*stack_a);
		rra(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
}

int		already_sorted(t_stack *stack)
{
	t_stack	*node;

	node = *stack;
	while (node->next != *stack)
	{
		if (node->next->nbr > node->next->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

void	sort_small(t_stack **stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size < 3)
		sa(stack);
	else
	{
		while (size > 3 && !already_sorted(*stack));
		// minimum_up
		pb(stack);
		size--;
	}
}