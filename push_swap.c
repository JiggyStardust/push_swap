/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/02 17:15:32 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *a, t_node *b)
{
	int	temp;
	
	temp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = temp->nbr;
	ft_printf("sa\n");
}
void	rra(t_node **stack_a)
{
		
}
void	ra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*last;

	temp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)-> = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	sort_three(t_node *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->nbr;
	b = stack_a->next->nbr;
	c = stack_a->next->next->nbr;
	if (a > b && b > c) // 3 2 1
		swap(*stack_a,  (*stack_a)->next); // 2 3 1
		rra(*stack_a); //1 2 3
	else if (a > c && c > b) // 3 1 2
		ra(&stack_a); // 1 2 3
	else if (b > a && b > c)// 1 3 2
	{
		rra(&stack_a); // 2 1 3
		swap(*stack_a, (*stack_a)->next); // 1 2 3
	}
	else if (a > b && c > a) // 2 1 3
		swap(*stack_a, (*stack_a)->next);  // 1 2 3
	else if (a > c && b > a) // 2 3 1
		rra(&stack_a); // 1 2 3
}

void	add_to_stack(t_node **stack, int nbr)
{
	t_node	*new_node;
	t_node	*temp;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nbr = nbr
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
	}
}

int	main(int ac, char **av)
{
	t_node	*stack_a = NULL;
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		add_to_stack(&stack_a, num);
		i++;
	}
	return (0);
}