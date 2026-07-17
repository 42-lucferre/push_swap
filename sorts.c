/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:36:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/17 00:49:54 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	*insertion_sort(int *stack_a, int *stack_b, int size)
// {
// 	int	i_a;
// 	int	i_b;

// 	//stack_b[0] = stack_a[0];
// 	i_a = 0;
// 	i_b = 1;
// 	while (i_a < size)
// 	{
// 		i_b = 1;
// 		while (stack_a[i_a] > stack_b[i_b] && i_b < size)
// 			i_b++;
// 		insert(stack_a[i_a], stack_b, i_b - 1);
// 		i_a++;
// 	}
// 	return (stack_b);
// }

int	*insertion_sort(int *stack_a, int *stack_b, int size)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	while (i < size)
	{
		index = min_finder(stack_a, size);
		j = 0;
		while (j < index)
		{
			// if (index <= size / 2)
			rotate(stack_a, size - i);
			// else
			// 	reverse_rotate(stack_a, size);
			j++;
		}
		push(stack_a, stack_b, size - i, i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		push(stack_b, stack_a, size, i);
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

// 1 
// 8 
// 9 
// 7 
// 3 
//   
//   