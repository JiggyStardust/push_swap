/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:25:55 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/08 11:31:34 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	t_stack	*last = *stack;
	t_stack	*before_last = NULL;

	while (last->next != *stack)
	{
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