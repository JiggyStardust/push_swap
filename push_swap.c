/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/03 15:15:25 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	if (stack->top && stack->size > 1)
	{
		t_node	*last;
		t_node	*before_last;

		last = stack->top;
		while (last->next != stack->top)
		{
			before_last = last;
			last = last->next;
		}
		stack->top = last;
		before_last->next = stack->top;
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
	if (stack->top && stack->size > 1)
	{
		t_node	*second;

		second = stack->top;
		second = second->next;
		stack->top = second;
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

void	swap(t_node **stack)
{
	if (stack->top && stack->size > 1)
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;	
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->nbr;
	b = stack_a->top->next->nbr;
	c = stack_a->top->next->next->nbr;
	if (a > b && b > c) // 3 2 1
		sa(&stack_a); // 2 3 1
		rra(&stack_a); //1 2 3
	else if (a > c && c > b) // 3 1 2
		ra(&stack_a); // 1 2 3
	else if (b > a && b > c)// 1 3 2
	{
		rra(&stack_a); // 2 1 3
		sa(&stack_a); // 1 2 3
	}
	else if (a > b && c > a) // 2 1 3
		sa(&stack_a);  // 1 2 3
	else if (a > c && b > a) // 2 3 1
		rra(&stack_a); // 1 2 3
}

void	add_to_stack(t_node *stack, int nbr)
{
	t_node	*new_node;
	t_node	*temp;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr;
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		temp = stack->top;
		while (temp->next != stack->top)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = stack->top;
	}
	stack->size++;
}

int	main(int ac, char **av)
{
	t_stack	stack_a = {NULL, 0};
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		i++;
	}
	if (stack_a.size == 3)
		sort_three(&stack_a);
	return (0);
}