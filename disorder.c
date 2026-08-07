/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:25:04 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/07 19:08:09 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(int *stack, int size)
{
	int	i;
	int	j;
	int	pairs;
	int	inversions;

	if (size < 2)
		return (0);
	pairs = (size * (size - 1)) / 2;
	i = 0;
	inversions = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] > stack[j])
				inversions++;
			j++;
		}
		i++;
	}
	return ((double)inversions / pairs);
}
