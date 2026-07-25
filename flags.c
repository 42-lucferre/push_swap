/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:50:59 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/25 13:25:04 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	flag_identifier(char **argv)
{
	int	sum;
	int	t;

	if (ft_strncmp(argv[1], argv[2], 12) == 0)
		return (-1);
	sum = 0;
	t = 0;
	sum += bench_identifier(**argv);
	if (argv[1][0] == '-')
	{	
		sum += bench_identifier(**argv);
		t += sum;
		sum += strat_flag(argv[t + 1]);
	}
	if (argv[1][0] == '-')
	sum += strat_flag();
}

int	bench_identifier(char **argv)
{
	int		sum;
	char	*bench;

	bench = "--bench";
	sum = 0;
	if (argv[1][0] == '-')
	{
		if (ft_strncmp(argv[1], argv[2], 12) == 0)
			return (-1);
		else if (ft_strncmp(argv[1], bench, 12) == 0)
		{
			sum += 16;
			if (argv[2][0] == '-')
				sum += strat_identifier(argv[2]);
		}
		else if (ft_strncmp(argv[2], bench, 12) == 0)
		{
			sum += 16;
			sum += strat_identifier(argv[1]);
		}
		else
			sum += strat_identifier(argv[1]);
	}
	return (sum);
}