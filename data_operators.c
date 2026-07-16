/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:03:57 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/16 00:48:24 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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