/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:40 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/08 20:17:55 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk_size(int stack_size)
{
	int	i;

	i = 1;
	while ((i * i) <= stack_size)
		i++;
	return (i - 1);
}

static int	top_distance(int *stack, int size, int start, int end)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] >= start && stack[i] < end)
			return (i);
		i++
	}
}


static int	bottom_distance(int *stack, int size, int start, int end)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] >= start && stack[i] < end)
			return (i);
		i++
	}
}