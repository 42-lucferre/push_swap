/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:42:36 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/12 01:04:25 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_printer(t_master *master)
{
	t_op	op_counter;

	op_counter = master->op_counter;
	write(2, "[bench] disorder: ", 18);
	disorder_printer(master);
	write(2, "\n[bench] strategy: ", 19);
	flag_printer(master);
	strat_printer(master);
	write(2, "\n[bench] total_ops: ", 20);
	ft_putnbr_fd(op_counter.total, 2);
	op_counter_printer(op_counter);
	write(2, "\n", 1);
}

void	disorder_printer(t_master *master)
{
	double	nmb;
	int		integer;
	int		decimal;

	nmb = master->disorder;
	integer = (int)nmb;
	ft_putnbr_fd(integer, 2);
	decimal = (int)((nmb - integer) * 100);
	write(2, ".", 1);
	ft_putnbr_fd(decimal, 2);
}

void	flag_printer(t_master *master)
{
	if (master->flags.has_adaptive)
		write(2, "Adaptive / ", 11);
	else if (master->flags.has_simple)
		write(2, "Simple / ", 9);
	else if (master->flags.has_simple)
		write(2, "Medium / ", 9);
	else if (master->flags.has_simple)
		write(2, "Complex / ", 10);
}

void	strat_printer(t_master *master)
{
	if (master->strat == STRAT_START)
		write(2, "Error", 5);
	else if (master->strat == STRAT_NONE)
		write(2, "None", 4);
	else if (master->strat == STRAT_SIMPLE)
		write(2, "O(n²)", 6);
	else if (master->strat == STRAT_MEDIUM)
		write(2, "O(n\xE2\x88\x9An)", 8);
	else if (master->strat == STRAT_COMPLEX)
		write(2, "O(n log n)", 10);
}

void	op_counter_printer(t_op op_counter)
{
	write(2, "\n[bench] sa: ", 13);
	ft_putnbr_fd(op_counter.sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(op_counter.sb, 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(op_counter.ss, 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(op_counter.pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(op_counter.pb, 2);
	write(2, "\n[bench] ra: ", 13);
	ft_putnbr_fd(op_counter.ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(op_counter.rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(op_counter.rr, 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(op_counter.rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(op_counter.rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(op_counter.rrr, 2);
}
