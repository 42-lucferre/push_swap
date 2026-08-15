/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_extra_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:59:53 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/15 14:16:28 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_index_chunk(t_master *master, int start, int chunk_size)
{
	int	index;
	int	i;

	index = -1;
	i = 0;
	while (i < master->size_b)
	{
		if (master->stack_b[i] >= start
			&& master->stack_b[i] < (start + chunk_size))
		{
			if (index == -1 || master->stack_b[i] > master->stack_b[index])
				index = i;
		}
		i++;
	}
	return (index);
}

static int	medium_b_to_a(t_master *master, int start, int chunk_size)
{
	int	index;
	int	i;

	index = max_index_chunk(master, start, chunk_size);
	if (index == -1)
		return (0);
	i = 0;
	while (i < index)
	{
		if (rotate(master->stack_b, master->size_b))
			rotate_printer(&master->op_counter, 'b');
		i++;
	}
	pa_operation(master);
	i = 0;
	while (i < index)
	{
		if (reverse_rotate(master->stack_b, master->size_b))
			r_rotate_printer(&master->op_counter, 'b');
		i++;
	}
	return (1);
}

void	sort_a_medium(t_master *master, int start, int chunk_size)
{
	int	start_check;

	while (master->size_b > 0)
	{
		start_check = medium_b_to_a(master, start, chunk_size);
		if (start_check == 0)
			start -= chunk_size;
	}
}
