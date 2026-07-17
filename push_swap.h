/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:21 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/17 00:50:19 by lucferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		main(int argc, char **argv);
int		*stack_creator(int argc, char **argv);
int		*insertion_sort(int *stack_a, int *stack_b, int size);
void	insert(int element_a, int *stack_b, int pos);
void	swap(int *stack, int size);
void	push(int *stack_a, int *stack_b, int size_a, int size_b);
void	rotate(int	*stack, int size);
void	reverse_rotate(int *stack, int size);
int		min_finder(int *stack, int size);

#endif