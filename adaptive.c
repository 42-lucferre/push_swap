/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorrea <jcorrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 10:51:31 by jcorrea           #+#    #+#             */
/*   Updated: 2026/08/08 11:15:31 by jcorrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strategy	adaptive(double disorder_value)
{
	if (disorder_value == 0)
		return (STRAT_NONE);
	else if (disorder_value < 0.2)
		return (STRAT_SIMPLE);
	else if (disorder_value < 0.5)
		return (STRAT_MEDIUM);
	else
		return (STRAT_COMPLEX);
}
