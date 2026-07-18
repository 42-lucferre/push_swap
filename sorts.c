/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:36:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/18 04:22:08 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*insertion_sort(int *stack_a, int *stack_b, int size, t_op *op_counter)
{
	int			i;
	int			current_size;
	int			index;

	op_counter->pa = 0;
	op_counter->pb = 0;
	i = 0;
	while (i < size)
	{
		current_size = size - i;
		index = min_finder(stack_a, current_size);
		rotation_direction(stack_a, index, current_size, op_counter);
		if (push(stack_a, stack_b, current_size, i))
			op_counter->pb++;
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (push(stack_b, stack_a, size, i))
			op_counter->pa++;
		i++;
	}
	return (stack_a);
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
			op_c->ra++;
			j++;
		}
	}
	else
	{
		while (j < current_size - index)
		{
			reverse_rotate(stack, current_size);
			op_c->rra++;
			j++;
		}
	}
}


// 1 8 4 3 4 8 7 8 9
// 8 9 8 4 8 9 8 9
// 9 7 9 8 9 7 9
// 7 3 7 9 7
// 3 4 3 7
// 4 

// pa 6
// pb 6
// ra
// rra 3