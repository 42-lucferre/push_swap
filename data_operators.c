/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:03:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/18 03:46:27 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap(int *stack, int size)
{
	int	tmp;

	if (size <= 1)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

int	push(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int	i;

	if (size_a <= 0)
		return (0);
	while (size_b > 0)
	{
		stack_b[size_b] = stack_b[size_b - 1];
		size_b--;
	}
	stack_b[0] = stack_a[0];
	i = 1;
	while (i < size_a)
	{
		stack_a[i - 1] = stack_a[i];
		i++;
	}
	return (1);
}

void	rotate(int	*stack, int size)
{
	int	tmp;
	int	i;

	if (size <= 1)
		return ;
	tmp = stack[0];
	i = 1;
	while (i < size)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[size - 1] = tmp;
}

void	reverse_rotate(int *stack, int size)
{
	int	tmp;

	if (size <= 1)
		return ;
	tmp = stack[size - 1];
	while (size > 1)
	{
		stack[size - 1] = stack[size - 2];
		size--;
	}
	stack[0] = tmp;
}
