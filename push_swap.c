/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/26 14:07:09 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *lst)
{
	int		nodes;
	t_stack	*temp;

	if (lst == NULL)
		return (0);
	nodes = 1;
	temp = lst;
	while (temp && temp->next != lst)
	{
		nodes++;
		temp = temp->next;
	}
	return (nodes);
}

static int	mod_atoi(char *str, int *error)
{
	long	minus;
	long	nbr;

	nbr = 0;
	minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	if (nbr > 2147483648 || (nbr == 21474483648 && minus != 1) || *str != '\0')
		*error = 1;
	if (*error == 1)
		return (0);
	if (minus == 1)
		nbr = nbr * (-1);
	return ((int)nbr);
}

static int	check_dup(t_stack *stack, int n)
{
	t_stack	*temp;

	if (stack_size(stack) < 1)
		return (0);
	if (stack->nbr == n)
		return (1);
	temp = stack;
	while (temp->next != stack)
	{
		if (temp->nbr == n)
			return (1);
		temp = temp->next;
	}
	return (0);
}

t_stack	*init_stack_a(char **args, int error)
{
	int		i;
	int		num;
	t_stack	*stack_a;

	i = 0;
	num = 0;
	stack_a = NULL;
	while (args[i] != NULL)
	{
		num = mod_atoi(args[i++], &error);
		if (error == 1 || check_dup(stack_a, num) == 1)
			free_after_error(stack_a, NULL, args);
		if (add_to_stack(&stack_a, num) == -1)
			free_after_error(stack_a, NULL, args);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		error;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	error = 0;
	args = handle_input(av, ac);
	if (!args)
		return (1);
	stack_a = init_stack_a(args, error);
	if (!stack_a)
		free_after_error(stack_a, stack_b, args);
	free_2d_arr(args);
	if (ac <= 6 && !already_sorted(stack_a))
		sort_small(&stack_a, &stack_b);
	else if (!already_sorted(stack_a))
		sort_big(&stack_a, &stack_b);
	while (stack_a)
		free_node(&stack_a);
	return (0);
}
