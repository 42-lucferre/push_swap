/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:54:19 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/18 19:05:15 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		ft_printf("sa\n");
		op_counter->sa++;
	}
	else if (stack == 'b')
	{
		ft_printf("sb\n");
		op_counter->sb++;
	}
	else
	{
		ft_printf("ss\n");
		op_counter->ss++;
	}
}

void	push_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		ft_printf("pa\n");
		op_counter->pa++;
	}
	else
	{
		ft_printf("pb\n");
		op_counter->pb++;
	}
}

void	rotate_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		ft_printf("ra\n");
		op_counter->ra++;
	}
	else if (stack == 'b')
	{
		ft_printf("rb\n");
		op_counter->rb++;
	}
	else
	{
		ft_printf("rr\n");
		op_counter->rr++;
	}
}

void	r_rotate_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		ft_printf("rra\n");
		op_counter->rra++;
	}
	else if (stack == 'b')
	{
		ft_printf("rrb\n");
		op_counter->rrb++;
	}
	else
	{
		ft_printf("rrr\n");
		op_counter->rrr++;
	}
}
