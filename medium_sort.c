/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:40 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/09 12:15:55 by jcorrea          ###   ########.fr       */
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
		i++;
	}
	return (-1);
}

static int	bottom_distance(int *stack, int size, int start, int end)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		if (stack[i] >= start && stack[i] < end)
			return (size - i);
		i--;
	}
	return (-1);
}

static void	better_rotation(t_master *master, int top_dist, int bottom_dist)
{
	int	i;

	if (top_dist == -1 && bottom_dist == -1)
		return ;
	if (top_dist <= bottom_dist)
	{
		i = top_dist;
		while (i > 0)
		{
			rotate(master->stack_a, master->size_a);
			rotate_printer(&master->op_counter, 'a');
			i--;
		}
	}
	else
	{
		i = bottom_dist;
		while (i > 0)
		{
			reverse_rotate(master->stack_a, master->size_a);
			r_rotate_printer(&master->op_counter, 'a');
			i--;
		}
	}
}

int	medium_sort(t_master *master)
{
	int	chunk_size;
	int	start;
	int	top_dist;
	int	bottom_dist;

	if ((rank_stack(master->stack_a, master->size_a)) == -1)
		return (-1);
	chunk_size = calc_chunk_size(master->size_a);
	start = 0;
	while (master->size_a > 0)
	{
		top_dist = top_distance(master->stack_a,
				master->size_a, start, (start + chunk_size));
		bottom_dist = bottom_distance(master->stack_a,
				master->size_a, start, (start + chunk_size));
		if (top_dist == -1 && bottom_dist == -1)
			start += chunk_size;
		else
		{
			better_rotation(master, top_dist, bottom_dist);
			pb_operation(master);
		}
	}
	return (0);
}
