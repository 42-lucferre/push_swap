/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:21 by lucferre          #+#    #+#             */
/*   Updated: 2026/07/18 04:20:37 by lucferre         ###   ########.fr       */
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

typedef struct s_op
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_op;

int		main(int argc, char **argv);
t_op	*stack_creator(int argc, char **argv);
void	init_counter(t_op *op_counter);
int		*insertion_sort(int *stack_a, int *stack_b, int size, t_op *op_counter);
void	insert(int element_a, int *stack_b, int pos);
void	swap(int *stack, int size);
int		push(int *stack_a, int *stack_b, int size_a, int size_b);
void	rotate(int	*stack, int size);
void	reverse_rotate(int *stack, int size);
int		min_finder(int *stack, int size);
void	rotation_direction(int *stack, int index, int current_size, t_op *op_c);

#endif