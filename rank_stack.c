/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:59:14 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/08 19:00:50 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*temp_stack(int *stack, int size)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp[i] = stack[i];
		i++;
	}
	return (temp);
}

int	rank_stack(int *stack, int size)
{
	int	*temp;
	int	rank;
	int	i;
	int	j;

	temp = temp_stack(stack, size);
	if (temp == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		rank = 0;
		j = 0;
		while (j < size)
		{
			if (temp[i] > temp[j])
				rank++;
			j++;
		}
		stack[i] = rank;
		i++;
	}
	free(temp);
	return (0);
}
