/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:27:38 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 15:33:25 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_in_stack(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = (*stack)->nbr;
	while (temp->next != *stack)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	if (min > temp->nbr)
		min = temp->nbr;
	return (min);
}

int	find_minimum(t_stack **stack)
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
	ratio = (float)min_node / (float)size;
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
