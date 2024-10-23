/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaraniemela <saaraniemela@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:23:51 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/23 18:34:02 by saaraniemel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
    if (*stack && (*stack)->next != *stack)
    {
        t_stack *first;
        t_stack *second;
        t_stack *third;

        first = *stack;
        second = first->next;
        first->next = second->next;
        second->next = first;
        third = *stack;
		while (third->next != *stack)
        	third = third->next;
		third->next = second;
        *stack = second;
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
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}