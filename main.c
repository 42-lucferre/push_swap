/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:26 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/11 00:42:16 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_decider(t_master *master)
{
	t_flags		flag;
	t_strategy	strat;

	flag = master->flags;
	if (!flag.has_simple && !flag.has_medium && !flag.has_complex)
		strat = adaptive(master->disorder);
	if (flag.has_simple || strat == STRAT_SIMPLE)
	{
		master->strat = STRAT_SIMPLE;
		selection_sort(master);
	}
	else if (flag.has_medium || strat == STRAT_MEDIUM)
	{
		master->strat = STRAT_MEDIUM;
		medium_sort(master);
	}
	else if (flag.has_complex || strat == STRAT_COMPLEX)
	{
		master->strat = STRAT_COMPLEX;
	// 	complex_sort(master);
	}
}

void	stack_creator(t_master *master)
{
	int		i;

	i = 0;
	while (i < master->size_a)
	{
		master->stack_a[i] = ft_atoi(master->args[i]);
		//master->stack_b[i] = 0;
		i++;
	}
	master->disorder = disorder(master->stack_a, master->size_a);
	sort_decider(master);
	free(master->stack_a);
	free(master->stack_b);
}

//#include <stdio.h>

int	main(int argc, char **argv)
{
	t_master	*master;

	if (argc <= 1)
		return (0);
	master = init_master(--argc, ++argv);
	if (!master || error_check(master) < 0)
		return (write(1, "Error\n", 6), 2);
	stack_creator(master);
	//printf("%f\n", master->disorder);
	//ft_printf("%d\n", master->strat);
	free(master);
	return (0);
}
