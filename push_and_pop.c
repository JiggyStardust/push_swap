/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:39:03 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/08 11:29:13 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_stack **stack)
{
	t_stack	*old_head;
	t_stack *last;

	if (*stack)
	{
		if ((*stack)->next == *stack)
		{
			free(*stack);
			*stack = NULL;
		}
		else
		{
		old_head = *stack;
		last = *stack;
		while (last->next != *stack)
			last = last->next;
		*stack = (*stack)->next;
		last->next = *stack;
		free(old_head);
		}
	}
}

// void print_stack_with_addresses(t_stack *stack)
// {
//     if (!stack)
//         return;
//     t_stack *temp = stack;
//     do
//     {
//         ft_printf("Node value: %d, Address: %p, Next address: %p\n", 
//                     temp->nbr, (void *)temp, (void *)temp->next);
//         temp = temp->next;
//     } while (temp != stack);
//     ft_printf("(back to start)\n");
// }


void	push(t_stack **dest_stack, t_stack *src_node)
{
	t_stack	*new_node;
	t_stack	*last;

	if (!src_node)
		return ; // nothing to push, add error handling later
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ; // add error handling later
	new_node->nbr = src_node->nbr;
	if (!*dest_stack) // stack empty
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
		return ; // add error handling later
	// print_stack_with_addresses(*stack_b);
	// print_stack_with_addresses(*stack_a);
	push(stack_b, *stack_a);
	ft_printf("pb\n");
	// print_stack_with_addresses(*stack_b);
	// print_stack_with_addresses(*stack_a);
	free_node(stack_a);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ; // add error handling later
	// print_stack_with_addresses(*stack_b);
	// print_stack_with_addresses(*stack_a);
	push(stack_a, *stack_b);
	ft_printf("pa\n");
	// print_stack_with_addresses(*stack_b);
	// print_stack_with_addresses(*stack_a);
	free_node(stack_b);
}