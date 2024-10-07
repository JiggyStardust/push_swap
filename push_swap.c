/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/07 15:17:54 by sniemela         ###   ########.fr       */
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

int		stack_size(t_stack *lst)
{
	int		nodes;
	t_stack	*temp;

	nodes = 1;
	temp = lst;
	while (temp && temp->next != lst)
	{
		nodes++;
		temp = temp->next;
	}
	return (nodes);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int	i;
	int	num;

	stack_a	= NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		ft_printf("Added %d to stack.\n", num);
		i++;
	}
	if (ac <= 10 && !already_sorted(stack_a))
		sort_small(&stack_a, &stack_b);
//	else
//		sort_big(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	return (0);
}
