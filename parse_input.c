/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sniemela <sniemela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:26:04 by sniemela          #+#    #+#             */
/*   Updated: 2024/10/24 11:41:41 by sniemela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**handle_input(char **av, int ac)
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
	arg[k] = '\0';
	ret = ft_split(arg, ' ');
	free(arg);
	return (ret);
}

