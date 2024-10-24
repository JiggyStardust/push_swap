/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:46:56 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 15:58:08 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_stack(t_stack **stack)
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

int	find_maximum(t_stack **stack)
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
