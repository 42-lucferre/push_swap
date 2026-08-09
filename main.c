/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:26 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/09 11:46:43 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -error -error -1
// -error -bench 15
// -error -simple -1
// -bench -error 15
// -bench -simple 17
// -bench number 16
// -simple -error 1
// -simple number 1

int	flag_check(t_master *master)
{
	if (flag_value(master->flags, master->args[0] < 0))
		return (0);
	else if (flag_value(master->flags, master->args[1] < 0))
		return (1);
	else
		return (2);
}

void	init_counter(t_op *op_counter)
{
	op_counter->sa = 0;
	op_counter->sb = 0;
	op_counter->ss = 0;
	op_counter->pa = 0;
	op_counter->pb = 0;
	op_counter->ra = 0;
	op_counter->rb = 0;
	op_counter->rr = 0;
	op_counter->rra = 0;
	op_counter->rrb = 0;
	op_counter->rrr = 0;
}

t_op	*stack_creator(int size, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		c;
	t_op	*op_counter;

	stack_a = malloc((size + 1) * sizeof(int));
	stack_b = malloc((size + 1) * sizeof(int));
	op_counter = malloc(sizeof(t_op));
	init_counter(op_counter);
	if (!stack_a || !stack_b || !op_counter)
		return (free(stack_a), free(stack_b), free(op_counter), NULL);
	c = 0;
	// ft_printf("size:%d\n", size);
	while (c < size)
	{
		stack_a[c] = ft_atoi(argv[c + 1]);
		//stack_b[c] = 0;
		//ft_printf("%d", ft_atoi(argv[c + 1]));
		c++;
	}
	stack_a = insertion_sort(master);
	free(stack_b);
	stack_a[size] = -1;
	return (op_counter);
}

int	main(int argc, char **argv)
{
	//int		*stack;
	//int		i;
	t_master	*master;

	master->args = ++argv;
	master->size = --argc;
	if (error_check(master) < 0)
		return (write(1, "Error\n", 6), 2);
	stack = stack_creator(argc - 1, argv);

	free(stack);
	return (0);
}

