/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:50:59 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/12 00:37:08 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_check(t_master *master)
{
	int		total_flags;
	t_flags	flag;

	if (master->size_a < 1)
		return (-1);
	if (master->size_a > 1)
	{
		if (ft_strncmp(master->args[0], master->args[1], 15) == 0)
			return (-1);
	}
	total_flags = flag_check(master);
	master->args += total_flags;
	master->size_a -= total_flags;
	if (rep_check(master->size_a, master->args) < 0)
		return (-1);
	if (int_check(master->size_a, master->args) < 0)
		return (-1);
	flag = master->flags;
	if (!flag.has_simple && !flag.has_medium && !flag.has_complex)
		master->flags.has_adaptive = 1;
	return (0);
}

int	rep_check(int size, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(args[i], args[j], 15) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

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

int	int_check(int size, char **args)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (-1);
		while (args[i][j] != '\0')
		{			
			if (args[i][j] < '0' || args[i][j] > '9')
				return (-1);
			j++;
		}
		num = ft_atoi_long(args[i]);
		if (num > MY_INT_MAX || num < MY_INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}
