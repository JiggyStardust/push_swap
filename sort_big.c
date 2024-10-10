/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:50:25 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/10 13:31:11 by sniemela         ###   ########.fr       */
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

void	cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int		max_node_a;
	int		max_node_b;
	int		size_a;
	int		size_b;
	float	ratio_a;
	float	ratio_b;

	max_node_a = find_maximum(stack_a);
//	printf("max_node_a: %i\n", max_node_a);
	max_node_b = find_maximum(stack_b);
//	printf("max_node_b: %i\n", max_node_b);
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	ratio_a = (float)max_node_a/(float)size_a;
//	printf("ratio_a: %f.2\n", ratio_a);
	ratio_b = (float)max_node_b/(float)size_b;
//	printf("ratio_b: %f.2\n", ratio_b);
	if (max_node_a == 1 && max_node_b == 1)
		ss(stack_a, stack_b);
	else if (max_node_b == 1 && max_node_a != 1)
		sb(stack_b);
	else if (max_node_a == 1 && max_node_b != 1)
		sa(stack_a);
	else if (ratio_a <= 0.5 && ratio_a != 0 && ratio_b != 0 && ratio_b <= 0.5) // or should ratio == 0.5 be handled in own function?
		rr(stack_a, stack_b);
	else if (ratio_a > 0.5 && ratio_b > 0.5)
		rrr(stack_a, stack_b);
	else if (ratio_a <= 0.5 && ratio_a != 0 && ratio_b > 0.5)
	{
		ra(stack_a);
		rrb(stack_b);
	}
	else if (ratio_a > 0.5 && ratio_b != 0 && ratio_b <= 0.5)
	{
		rra(stack_b);
		rb(stack_b);
	}
}

void	max_up(t_stack **stack, int size)
{
	int		max_node;
	float	ratio;

//	printf("size: %d\n", size);
	max_node = find_maximum(stack);
//	printf("max_node: %d\n", max_node);
	ratio = (float)max_node/(float)size;
//	printf("ratio: %f.2\n", ratio);
	if (max_node == 1)
		sa(stack);
	else if (ratio <= 0.5) // or should ratio == 0.5 be handled in own function?
		rb(stack);
	else if (ratio > 0.5)
		rrb(stack);
}
int		max_in_stack(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	
	temp = *stack;
	max = (*stack)->nbr;
	while (temp->next != *stack)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
	}
	if (max < temp->nbr)
		max = temp->nbr;
	return (max);
}

int		min_in_stack(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	
	temp = *stack;
	min = (*stack)->nbr;
	while (temp->next != *stack)
	{
		if (min < temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	if (min < temp->nbr)
		min = temp->nbr;
	return (min);
}

/*
int		count_moves(int src_i, int dest_i, int src_size, int dest_size) 
{
	int		moves;
	float	ratio_a;
	float	ratio_b;

	moves = 1; // or should I include pb already?
	ratio_a = (float)src_i/(float)src_size;
	ratio_b = (float)dest_i/(float)dest_size;
	while (ratio_a != 0 && src_i != src_size - 1) // how many moves until node is on top of stack_a?
	{
		if (ratio_a <= 0.5)
		{
			moves++;
			src_i--;
		}
		if (ratio_a > 0.5)
		{
			moves--;
			src_i++;
		}
	}
	while (ratio_b != 0 && dest_i != dest_size - 1 && dest_i != 0) // how many moves until node is at the desired spot in stack_b?
	{
		if (ratio_b <= 0.5 && ratio_a <= 0.5)
		{
			moves = moves - dest_i 
		}
		else if (ratio_b > 0.5 && ratio_a >= 0.5)
		{
			moves++;
			dest_i++;
		}
		else if (ratio_b > 0.5 && ratio_a < 0.5) // separate handlin for this, it's dependant on ratio_a
		{
			moves++;
			dest_i++;
		}
	}
	return (moves);
}*/

int		find_index_in_stack(int n, t_stack	**stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (n != temp->nbr)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_size(*stack_a) > 0)
	{
		if ((*stack_a)->nbr > (*stack_b)->nbr && find_maximum(stack_b) == 0)
			pb(stack_a, stack_b);
		else if ((*stack_a)->nbr > (*stack_b)->nbr && find_maximum(stack_b) != 0)
		{
			// print_stack(*stack_a);
			// print_stack(*stack_b);
			// ft_printf("mennaan max_up_b\n");
			max_up(stack_b, stack_size(*stack_b));
		}
		else if ((*stack_a)->nbr < (*stack_b)->nbr && find_maximum(stack_a) != 0 && find_maximum(stack_b) == 0)
		{
			// print_stack(*stack_a);
			// print_stack(*stack_b);
			// ft_printf("mennaan max_up_a\n");
			max_up(stack_a, stack_size(*stack_a));
		}
		else if ((*stack_a)->nbr < (*stack_b)->nbr && find_maximum(stack_a) == 0 && find_maximum(stack_b) == 0)
			pb(stack_a, stack_b);
		else
		{
			// print_stack(*stack_a);
			// print_stack(*stack_b);
			// ft_printf("mennaan cheapest move\n");
			cheapest_move(stack_a, stack_b);
		}
	}
	while (stack_size(*stack_b) > 0)
	{
		if (find_maximum(stack_b) == 0)
			pa(stack_a, stack_b);
		else
			max_up(stack_b, stack_size(*stack_b));
	}
}
