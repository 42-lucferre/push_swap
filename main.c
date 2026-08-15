/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:26 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/14 16:08:19 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_decider(t_master *master)
{
	t_flags		flag;

	flag = master->flags;
	if (flag.has_adaptive)
		master->strat = adaptive(master->disorder);
	if (master->strat == STRAT_NONE)
		return ;
	if (flag.has_simple || master->strat == STRAT_SIMPLE)
	{
		master->strat = STRAT_SIMPLE;
		selection_sort(master);
	}
	else if (flag.has_medium || master->strat == STRAT_MEDIUM)
	{
		master->strat = STRAT_MEDIUM;
		medium_sort(master);
	}
	else if (flag.has_complex || master->strat == STRAT_COMPLEX)
	{
		master->strat = STRAT_COMPLEX;
		complex_sort(master);
	}
}

int	stack_creator(t_master *master)
{
	int		i;

	if (master->split > 0)
	{
		free(master->stack_a);
		free(master->stack_b);
		master->stack_a = malloc(master->size_a * sizeof(int));
		master->stack_b = malloc(master->size_a * sizeof(int));
		if (!master->stack_a || !master->stack_b)
			return (-1);
	}
	i = 0;
	while (i < master->size_a)
	{
		master->stack_a[i] = ft_atoi(master->args[i]);
		i++;
	}
	master->disorder = disorder(master->stack_a, master->size_a);
	sort_decider(master);
	if (master->flags.has_bench)
		bench_printer(master);
	return (0);
}

int	main(int argc, char **argv)
{
	t_master	*master;

	if (argc <= 1)
		return (0);
	master = init_master(--argc, ++argv);
	if (!master)
		return (write(1, "Error\n", 6), 2);
	if (error_check(master) < 0)
		return (free_all(master), write(1, "Error\n", 6), 2);
	if (stack_creator(master) < 0)
		return (free_all(master), write(1, "Error\n", 6), 2);
	free_all(master);
	return (0);
}
