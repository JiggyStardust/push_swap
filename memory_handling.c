/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:19:51 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 11:22:00 by sniemela         ###   ########.fr       */
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

void	free_2d_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

void	free_after_error(t_stack **a, t_stack **b, char **str)
{
	while (a)
		free_node(a);
	while (b)
		free_node(b);
	if (str && *str)
		free_2d_arr(str);
	ft_printf("Error\n");
}
