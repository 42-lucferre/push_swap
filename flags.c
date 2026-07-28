/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:50:59 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/28 00:28:06 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_init(t_flags *flags)
{
	flags->has_bench = 0;
	flags->has_simple = 0;
	flags->has_medium = 0;
	flags->has_complex = 0;
	flags->has_adaptive = 0;
}

int	flag_identifier(int size, char **argv)
{
	int		sum;
	t_flags	*flags;

	if (ft_strncmp(argv[1], argv[2], 12) == 0)
		return (-1);
	flag_init(flags);
	sum = 0;
	sum += bench_identifier(**argv, flags);
	if (sum == -1)
		return (-1);
	if (sum == 1)
	{
		if (argv[2][0] == '-')
		{
			if (strat_flag(argv[2]) == -1)
				return (-1);
		}
	}
	else
	{
		if (strat_flag(argv[1]) == -1)
			return (-1);
	}
	flag_parser(size, **argv, flags);
	return (0);
}

int	bench_identifier(char **argv, t_flags *flags)
{
	char	*bench;

	bench = "--bench";
	if (argv[1][0] == '-')
	{
		if (ft_strncmp(argv[1], bench, 12) == 0)
		{	
			flags->has_bench = 1;
			return (0);
		}
		if (ft_strncmp(argv[2], bench, 12) == 0)
		{	
			flags->has_bench = 2;
			return (0);
		}
		else
			return (-1);
	}
	return (0);
}
