/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:36:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/09 14:43:39 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_master *master)
{
	int			index;

	while (master->size_a > 0)
	{
		index = min_finder(master->stack_a, master->size_a);
		rotation_direction(master->stack_a, index, master->size_a,
			&master->op_counter);
		pb_operation(master);
	}
	while (master->size_b > 0)
		pa_operation(master);
}

int	min_finder(int *stack, int size)
{
	int	min;
	int	index;

	min = stack[0];
	index = 0;
	while (size > 0)
	{
		if (stack[size -1] < min)
		{
			min = stack[size -1];
			index = size - 1;
		}
		size--;
	}
	return (index);
}

void	rotation_direction(int *stack, int index, int current_size, t_op *op_c)
{
	int	j;

	j = 0;
	if (index <= current_size / 2)
	{
		while (j < index)
		{
			rotate(stack, current_size);
			rotate_printer(op_c, 'a');
			j++;
		}
	}
	else
	{
		while (j < current_size - index)
		{
			reverse_rotate(stack, current_size);
			r_rotate_printer(op_c, 'a');
			j++;
		}
	}
}
