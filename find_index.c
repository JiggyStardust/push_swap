/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:33:52 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 12:27:36 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_in_src(int nbr, t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (nbr != temp->nbr)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_index_in_a(int n, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		min_i;
	int		max_i;

	i = 0;
	max_i = find_index_in_src(max_in_stack(stack), stack);
	min_i = find_index_in_src(min_in_stack(stack), stack);
	if (n > max_in_stack(stack))
	{
		if (min_i < max_i + 1)
			i = min_i;
		else
			i = max_i + 1;
		return (i);
	}
	if (n < min_in_stack(stack))
	{
		i = min_i;
		return (i);
	}
	i = 1;
	temp = *stack;
	while (temp->next != *stack)
	{
		if (n > temp->nbr && n < temp->next->nbr)
			break ;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_index_in_b(int n, t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		min_i;
	int		max_i;

	i = 0;
	max_i = find_index_in_src(max_in_stack(stack), stack);
	min_i = find_index_in_src(min_in_stack(stack), stack);
	if (n > max_in_stack(stack))
	{
		i = max_i;
		return (i);
	}
	if (n < min_in_stack(stack))
	{
		if (min_i + 1 < max_i)
			i = min_i + 1;
		else
			i = max_i;
		return (i);
	}
	i = 1;
	temp = *stack;
	while (temp->next != *stack && !(n < temp->nbr && n > temp->next->nbr))
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_index_in_dest(int n, t_stack **stack, char stack_f)
{
	int	i;

	if (stack_f == 'b')
		i = find_index_in_b(n, stack);
	else
		i = find_index_in_a(n, stack);
	return (i);
}