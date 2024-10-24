/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:46:56 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 11:51:21 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		find_maximum(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	int		node;
	
	temp = *stack;
	max = max_in_stack(stack);
	node = 0;
	while (temp->next != *stack && temp->nbr != max)
	{
		temp = temp->next;
		node++;
	}
	return (node);
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
