/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:27:38 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/08 13:22:44 by sniemela         ###   ########.fr       */
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
//		print_stack(*stack_a);
		ra(stack_a); // 2 1 3
//		print_stack(*stack_a);
		sa(stack_a); //1 2 3
//		print_stack(*stack_a);
	}
	else if (a > c && c > b) // 3 1 2
	{
//		print_stack(*stack_a);
		ra(stack_a); // 1 2 3
//		print_stack(*stack_a);
	}
	else if (a < c && b > c)// 1 3 2 
	{
//		print_stack(*stack_a);
		rra(stack_a); // 2 1 3
//		print_stack(*stack_a);
		sa(stack_a); // 1 2 3
//		print_stack(*stack_a);
	}
	else if (a > b && c > a) // 2 1 3
	{
//		print_stack(*stack_a);	
		sa(stack_a);  // 1 2 3
//		print_stack(*stack_a);
	}
	else if (a > c && b > a) // 2 3 1
	{
//		print_stack(*stack_a);
		rra(stack_a); // 1 2 3
//		print_stack(*stack_a);
	}
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
	min = (*stack)->nbr;
	node = 0;
	while (temp->next != *stack)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	temp = *stack;
	while (min != temp->nbr)
	{
		temp = temp->next;
		node++;
	}
	return (node);
}

void	min_up(t_stack **stack, int size)
{
	int		min_node;
	float	ratio;
	
	min_node = find_minimum(stack);
//	printf("min_node: %d\n", min_node);
	ratio = (float)min_node/(float)size;
//	printf("middle: %f.2\n", middle);
	if (ratio <= 0.5) // min_node is at the beginning of the list
	{
		while (min_node != 0)
		{
			ra(stack);
			min_node--;
		}
	}
	else if (ratio > 0.5) // min_node is at the end of the list
	{
		while (min_node != size)
		{
			rra(stack);
			min_node++;
		}
	}
}

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

//	ft_printf("sort small\n");
	size = stack_size(*stack_a);
//	ft_printf("stack size is: %d\n", size);
	if (size < 3)
		sa(stack_a);
	else if (size > 3)
	{
		while (size > 3 && !already_sorted(*stack_a))
		{
			min_up(stack_a, size);
			pb(stack_a, stack_b);
//			ft_printf("stack_b: ");
//			print_stack(*stack_b);
//			ft_printf("stack_a: ");
//			print_stack(*stack_a);
			size--;
		}
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
//		ft_printf("stack_a: ");
//		print_stack(*stack_a);
	}
}
