/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:36:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/16 00:46:47 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*insertion_sort(int *stack_a, int *stack_b, int size)
{
	int	i_a;
	int	i_b;

	//stack_b[0] = stack_a[0];
	i_a = 0;
	i_b = 1;
	while (i_a < size)
	{
		i_b = 1;
		while (stack_a[i_a] > stack_b[i_b] && i_b < size)
			i_b++;
		insert(stack_a[i_a], stack_b, i_b - 1);
		i_a++;
	}
	return (stack_b);
}

void	insert(int element_a, int *stack_b, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[i] = element_a;
}

// 1 0 1
// 8 013
// 9 037
// 7 078
// 3 08
//   0
//   12