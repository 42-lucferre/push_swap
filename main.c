/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:26 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/16 00:24:03 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_creator(int size, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	c;

	stack_a = malloc((size + 1) * sizeof(int));
	stack_b = malloc((size + 1) * sizeof(int));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), NULL);
	c = 0;
	while (c < size)
	{
		stack_a[c] = ft_atoi(argv[c + 1]);
		stack_b[c] = 0;
		//ft_printf("%d", ft_atoi(argv[c + 1]));
		c++;
	}
	stack_b = insertion_sort(stack_a, stack_b, size);
	free(stack_a);
	stack_b[size] = -1;
	return (stack_b);
}

int	main(int argc, char **argv)
{
	int	*stack;
	int	i;

	stack = stack_creator(argc - 1, argv);
	i = 0;
	while (stack[i] != -1)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
	free(stack);
	return (0);
}
