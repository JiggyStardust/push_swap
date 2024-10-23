/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:21:28 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/23 15:11:12 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_in_stack(t_stack **stack)
{
	t_stack	*temp;
	int		max;
	
	temp = *stack;
	max = (*stack)->nbr;
	while (temp->next != *stack)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
	}
	if (max < temp->nbr)
		max = temp->nbr;
	return (max);
}

int		min_in_stack(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	
	temp = *stack;
	min = (*stack)->nbr;
	while (temp->next != *stack)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	if (min > temp->nbr)
		min = temp->nbr;
	return (min);
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

static int	get_length(char **av, int ac)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]) + 1;
		i++;
	}
	return (len);
}

static char	**handle_input(char **av, int ac)
{
	char	*arg;
	char	**ret;
	int		i;
	int		j;
	int 	k;

	arg = (char *)malloc(get_length(av, ac) * sizeof(char));
	if (!arg)
		return (NULL);
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			arg[k++] = av[i][j++];
		if (i < ac - 1)
			arg[k++] = ' ';
		i++;
	}
	ret = ft_split(arg, ' ');
	free(arg);
	return (ret);
}

static int	mod_atoi(char **str)
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
	if (nbr < 0 && minus == 1)
		return (0);
	if (nbr < 0)
		return (-1);
	if (minus == 1)
		nbr = nbr * (-1);
	return ((int)nbr);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;
	int		num;

	if (ac < 2)
		return (0);
	args = handle_input(av, ac);
	if (!args)
		return (1);
	stack_a	= NULL;
	stack_b = NULL;
	i = 0;
	while (args[i] != NULL)
	{
		num = ft_atoi(args[i]);
		add_to_stack(&stack_a, num);
		i++;
	}
	free_2d_arr(args);
	if (ac <= 5 && !already_sorted(stack_a))
		sort_small(&stack_a, &stack_b);
	else if (!already_sorted(stack_a))
		sort_big(&stack_a, &stack_b);
	while (stack_a)
		free_node(&stack_a);
	return (0);
}

