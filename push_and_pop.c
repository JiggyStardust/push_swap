/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:39:03 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 12:22:22 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest_stack, t_stack *src_node)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!src_node)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = src_node->nbr;
	if (!*dest_stack)
	{
		new_node->next = new_node;
		*dest_stack = new_node;
	}
	else
	{
		new_node->next = *dest_stack;
		last = *dest_stack;
		while (last->next != *dest_stack)
			last = last->next;
		last->next = new_node;
		*dest_stack = new_node;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return ;
	push(stack_b, *stack_a);
	ft_printf("pb\n");
	free_node(stack_a);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ;
	push(stack_a, *stack_b);
	ft_printf("pa\n");
	free_node(stack_b);
}
