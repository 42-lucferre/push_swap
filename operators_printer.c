/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:54:19 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/13 23:48:51 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		if (op_counter->print)
			ft_printf("sa\n");
		op_counter->sa++;
		op_counter->total++;
	}
	else if (stack == 'b')
	{
		if (op_counter->print)
			ft_printf("sb\n");
		op_counter->sb++;
		op_counter->total++;
	}
	else
	{
		if (op_counter->print)
			ft_printf("ss\n");
		op_counter->ss++;
		op_counter->total++;
	}
}

void	push_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		if (op_counter->print)
			ft_printf("pa\n");
		op_counter->pa++;
		op_counter->total++;
	}
	else
	{
		if (op_counter->print)
			ft_printf("pb\n");
		op_counter->pb++;
		op_counter->total++;
	}
}

void	rotate_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		if (op_counter->print)
			ft_printf("ra\n");
		op_counter->ra++;
		op_counter->total++;
	}
	else if (stack == 'b')
	{
		if (op_counter->print)
			ft_printf("rb\n");
		op_counter->rb++;
		op_counter->total++;
	}
	else
	{
		if (op_counter->print)
			ft_printf("rr\n");
		op_counter->rr++;
		op_counter->total++;
	}
}

void	r_rotate_printer(t_op *op_counter, char stack)
{
	if (stack == 'a')
	{
		if (op_counter->print)
			ft_printf("rra\n");
		op_counter->rra++;
		op_counter->total++;
	}
	else if (stack == 'b')
	{
		if (op_counter->print)
			ft_printf("rrb\n");
		op_counter->rrb++;
		op_counter->total++;
	}
	else
	{
		if (op_counter->print)
			ft_printf("rrr\n");
		op_counter->rrr++;
		op_counter->total++;
	}
}
