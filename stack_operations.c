/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 11:36:41 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/14 15:35:37 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_operation(t_master *master)
{
	if (push(master->stack_a, master->stack_b, master->size_a,
			master->size_b))
	{
		push_printer(&master->op_counter, 'b');
		master->size_a--;
		master->size_b++;
	}
}

void	pa_operation(t_master *master)
{
	if (push(master->stack_b, master->stack_a, master->size_b,
			master->size_a))
	{
		push_printer(&master->op_counter, 'a');
		master->size_b--;
		master->size_a++;
	}
}

void	ra_operation(t_master *master)
{
	rotate(master->stack_a, master->size_a);
	rotate_printer(&master->op_counter, 'a');
}
