/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/04 16:03:36 by sniemela         ###   ########.fr       */
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


void	rev_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	t_stack	*last = *stack;
	t_stack	*before_last = NULL;

	while (last->next != *stack)
	{
		ft_printf("Current last: %d, next: %d\n", last->nbr, last->next->nbr);
		before_last = last;
		last = last->next;
	}
	if (before_last)
	{
		last->next = *stack;
		before_last->next = last;
		*stack = last;
	}
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
void	rotate(t_stack **stack)
{
	if (*stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
	}
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}

void swap(t_stack **stack)
{
    if (*stack && (*stack)->next != *stack)
    {
        ft_printf("SWAP HAPPENS\n");
        t_stack *first;
        t_stack *second;
        t_stack *third;

        first = *stack;
        second = first->next;
        third = second->next;

        // Swap the first two nodes
        second->next = first;
        first->next = third;

        // If the list is circular, make sure the new last node points to the new head
        if (third != NULL)
        {
            t_stack *last = third;
            while (last->next != *stack) // Traverse until the end of the circular list
            {
                last = last->next;
            }
            last->next = second;  // Make the new last point to the new head
        }
        *stack = second; // Update the head of the stack
    }
}


void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

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
		print_stack(*stack_a);
		ra(stack_a); // 2 1 3
		print_stack(*stack_a);
		sa(stack_a); //1 2 3
		print_stack(*stack_a);
	}
	else if (a > c && c > b) // 3 1 2
	{
		print_stack(*stack_a);
		ra(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
	else if (a < c && b > c)// 1 3 2 
	{
		print_stack(*stack_a);
		rra(stack_a); // 2 1 3
		print_stack(*stack_a);
		sa(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
	else if (a > b && c > a) // 2 1 3
	{
		print_stack(*stack_a);	
		sa(stack_a);  // 1 2 3
		print_stack(*stack_a);
	}
	else if (a > c && b > a) // 2 3 1
	{
		print_stack(*stack_a);
		rra(stack_a); // 1 2 3
		print_stack(*stack_a);
	}
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

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a	= NULL;

	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		ft_printf("Added %d to stack.\n", num);
		i++;
	}
	if (ac == 4)
		sort_three(&stack_a);
	return (0);
}