/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:50:59 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/09 11:46:05 by lucferre         ###   ########.fr       */
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

int	error_check(t_master *master)
{
	int	r;

	if (master->size < 1)
		return (-1);
	if (rep_check(master->size, master->args) < 0)
		return (-1);
	r = flag_check(master);
	master->args += r;
	master->size -+ r;
	if (int_check(master->size, master->args) < 0)
		return (-1);
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

int	flag_value(t_flags flag, char *arg)
{
	if (ft_strncmp(arg, "--bench", 12) == 0)
		return (flag.has_bench = 1, 0);
	else if (ft_strncmp(arg, "--simple", 12) == 0)
		return (flag.has_simple = 1, 0);
	else if (ft_strncmp(arg, "--medium", 12) == 0)
		return (flag.has_medium = 1, 0);
	else if (ft_strncmp(arg, "--complex", 12) == 0)
		return (flag.has_complex = 1, 0);
	else if (ft_strncmp(arg, "--adaptive", 12) == 0)
		return (flag.has_adaptive = 1, 0);
	else
		return (-1);
}

int int_check(int size, char **args)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (j == 0)
			{
				if (args[i][j] == '-')
					j++;
			}				
			if (args[i][j] <= '0' || args[i][j] >= '9')
				return (-1);
			j++;
		}
			i++;
	}
	return (0);
}

0 15
1 48
2 43
3 97