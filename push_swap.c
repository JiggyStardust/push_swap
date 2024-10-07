/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/07 10:07:44 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
    if (!stack)
    {
        ft_printf("Stack is empty\n");
        return;
    }
    t_stack *current = stack;
    int count = 0;  // Counter to limit printing to 4 elements

    while (current && count < 4)
    {
        ft_printf("%d -> ", current->nbr);
        current = current->next;
        count++;

        // Check if we have reached the head again to stop
        if (current == stack)
            break;
    }

    if (count == 4)
        ft_printf("...\n");  // Indicate more elements if the list exceeds 4
    else
        ft_printf("(back to %d)\n", stack->nbr);
}

void	add_to_stack(t_stack **stack, int nbr)
{
	t_stack	*new_node;
	t_stack	*temp;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = *stack;
	}
	else
	{
		temp = *stack;
		while (temp->next != *stack)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = *stack;
	}
}
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
	push(stack_b, *stack_a);
	free_node(stack_a);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return ; // add error handling later
	push(stack_a, *stack_b);
	free_node(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	int	i;
	int	num;

	stack_a	= NULL;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		ft_printf("Added %d to stack.\n", num);
		i++;
	}
	if (ac <= 10 && !already_sorted(&stack))
		sort_small(&stack_a);
	else
		sort_big(&stack_a);
	return (0);
}
