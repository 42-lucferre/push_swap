/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:26 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/14 23:18:26 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_creator(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	c;

	stack_a = malloc((argc) * sizeof(int));
	stack_b = malloc((argc + 1) * sizeof(int));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), NULL);
	c = 0;
	while (c < argc - 1)
	{
		stack_a[c] = ft_atoi(argv[c + 1]);
		//ft_printf("%d", ft_atoi(argv[c + 1]));
		c++;
	}
	stack_a[argc - 1] = -1;
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int	*stack;
	int	i;

	stack = stack_creator(argc, argv);
	i = 0;
	while (stack[i] != -1)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	free(stack);
	return (0);
}
