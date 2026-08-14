/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:10:49 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/14 15:54:46 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_rank_bit(int size)
{
	int	n_bits;
	int	max_rank;

	n_bits = 0;
	max_rank = size - 1;
	while (max_rank > 0)
	{
		max_rank >>= 1;
		n_bits++;
	}
	return (n_bits);
}

static void	radix_pass(t_master *master, int bit)
{
	int	i;
	int	size;

	size = master->size_a;
	i = 0;
	while (i < size)
	{
		if (((master->stack_a[0] >> bit) & 1) == 0)
			pb_operation(master);
		else
			ra_operation(master);
		i++;
	}
	while (master->size_b > 0)
		pa_operation(master);
}

int	complex_sort(t_master *master)
{
	int	n_bits;
	int	bit;

	if ((rank_stack(master->stack_a, master->size_a)) == -1)
		return (-1);
	n_bits = max_rank_bit(master->size_a);
	bit = 0;
	while (bit < n_bits)
	{
		radix_pass(master, bit);
		bit++;
	}
	return (0);
}
