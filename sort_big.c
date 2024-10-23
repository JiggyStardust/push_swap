/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:50:25 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/23 18:34:07 by saaraniemel      ###   ########.fr       */
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

	max_node = find_maximum(stack);
	size = stack_size(*stack);
	ratio = (float)max_node/(float)size;
	if (ratio <= 0.5)
		rb(stack);
	else if (ratio > 0.5)
		rrb(stack);
}

int		find_index_in_src(int nbr, t_stack **stack)
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

int		find_index_in_a(int n, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		min_i;
	int		max_i;

	i = 0;
	max_i = find_index_in_src(max_in_stack(stack), stack);
	min_i = find_index_in_src(min_in_stack(stack), stack);
	if (n > max_in_stack(stack))
	{
		if (min_i < max_i + 1)
			i = min_i;
		else
			i = max_i + 1;
		return (i);
	}
	if (n < min_in_stack(stack))
	{
		i = min_i;
		return (i);
	}
	i = 1;
	temp = *stack;
	while (temp->next != *stack)
	{
		if (n > temp->nbr && n < temp->next->nbr)
			break;
		temp = temp->next;
		i++;
	}
	return (i);
}

int		find_index_in_b(int n, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		min_i;
	int		max_i;

	i = 0;
	max_i = find_index_in_src(max_in_stack(stack), stack);
	min_i = find_index_in_src(min_in_stack(stack), stack);
	if (n > max_in_stack(stack))
	{
		i = max_i;
		return (i);
	}
	if (n < min_in_stack(stack))
	{
		if (min_i + 1 < max_i)
			i = min_i + 1;
		else
			i = max_i;
		return (i);
	}
	i = 1;
	temp = *stack;
	while (temp->next != *stack && !(n < temp->nbr && n > temp->next->nbr))
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int		find_index_in_dest(int n, t_stack **stack, char stack_f)
{
	int	i;

	if (stack_f == 'b')
		i = find_index_in_b(n, stack);
	else
		i = find_index_in_a(n, stack);
	return (i);
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

