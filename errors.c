/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 22:20:10 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/13 00:21:52 by lucferre         ###   ########.fr       */
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
	if (space_check(master) < 0)
		return (-1);
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

int	space_check(t_master *master)
{
	int		i;
	char	**split_args;

	i = 0;
	while (master->size_a > 0 && master->args[0][i] != '\0')
	{
		if (master->args[0][i] == ' ')
		{
			if (master->size_a > 1)
				return (-1);
			split_args = ft_split(master->args[0], ' ');
			if (!split_args)
				return (-1);
			master->args = split_args;
			master->split += 1;
			i = 0;
			while (master->args[i] != NULL)
				i++;
			master->size_a = i;
			return (0);
		}
		i++;
	}
	return (0);
}

void	free_all(t_master *master)
{
	int	i;

	if (!master)
		return ;
	free(master->stack_a);
	free(master->stack_b);
	if (master->split > 0)
	{
		i = 0;
		while (master->args[i] != NULL)
		{
			free(master->args[i]);
			i++;
		}
		free(master->args);
	}
	free(master);
}
