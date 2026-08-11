/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:08:02 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/10 23:58:03 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_flags(t_flags *flags)
{
	flags->has_bench = 0;
	flags->has_simple = 0;
	flags->has_medium = 0;
	flags->has_complex = 0;
	flags->has_adaptive = 0;
}

t_master	*init_master(int size, char **args)
{
	t_master	*master;

	master = malloc(sizeof(t_master));
	if (!master)
		return (NULL);
	master->stack_a = malloc(size * sizeof(int));
	if (!master->stack_a)
		return (free(master), NULL);
	master->stack_b = malloc(size * sizeof(int));
	if (!master->stack_b)
		return (free(master->stack_a), free(master), NULL);
	master->size_a = size;
	master->args = args;
	init_counter(&master->op_counter);
	init_flags(&master->flags);
	master->strat = STRAT_NONE;
	master->disorder = disorder(master->stack_a, size);
	return (master);
}
