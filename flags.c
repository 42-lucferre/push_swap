/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:50:59 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/14 00:07:47 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_check(t_master *master)
{
	if (flag_value(&master->flags, master->args[0]) < 0)
		return (0);
	if (master->size_a > 1)
	{
		if (flag_value(&master->flags, master->args[1]) < 0)
			return (1);
		else
			return (2);
	}
	return (1);
}

int	flag_value(t_flags *flag, char *arg)
{
	if (ft_strncmp(arg, "--bench", 12) == 0)
		return (flag->has_bench = 1, 0);
	else if (ft_strncmp(arg, "--simple", 12) == 0)
		return (flag->has_simple = 1, 0);
	else if (ft_strncmp(arg, "--medium", 12) == 0)
		return (flag->has_medium = 1, 0);
	else if (ft_strncmp(arg, "--complex", 12) == 0)
		return (flag->has_complex = 1, 0);
	else if (ft_strncmp(arg, "--adaptive", 12) == 0)
		return (flag->has_adaptive = 1, 0);
	else
		return (-1);
}
