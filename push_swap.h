/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucferre <lucferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 22:47:21 by lucferre          #+#    #+#             */
/*   Updated: 2026/08/09 14:49:30 by lucferre         ###   ########.fr       */
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

typedef struct s_flags
{
	int	has_bench;
	int	has_simple;
	int	has_medium;
	int	has_complex;
	int	has_adaptive;
}		t_flags;

typedef enum e_strategy
{
	STRAT_NONE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}		t_strategy;

typedef struct s_master
{
	t_strategy	strat;
	t_op		op_counter;
	t_flags		flags;
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
	double		disorder;
	char		**args;
}				t_master;

// Flags & errors
int			error_check(t_master *master);
int			rep_check(int size, char **args);
int			flag_check(t_master *master);
int			flag_value(t_flags flag, char *arg);
int			int_check(int size, char **args);

// Initializers
void		init_flags(t_flags flags);
t_master	*init_master(int size, char **args);
void		init_counter(t_op op_counter);

// Operators

int			main(int argc, char **argv);
void		stack_creator(t_master *master);
void		selection_sort(t_master *master);
void		insert(int element_a, int *stack_b, int pos);
void		swap(int *stack, int size);
int			push(int *stack_a, int *stack_b, int size_a, int size_b);
void		rotate(int *stack, int size);
void		reverse_rotate(int *stack, int size);
int			min_finder(int *stack, int size);
void		rotation_direction(int *stack, int index,
				int current_size, t_op *op_c);
void		swap_printer(t_op *op_counter, char stack);
void		push_printer(t_op *op_counter, char stack);
void		rotate_printer(t_op *op_counter, char stack);
void		r_rotate_printer(t_op *op_counter, char stack);
double		disorder(int *stack, int size);
t_strategy	adaptive(double disorder_value);
int			rank_stack(int *stack, int size);
void		pb_operation(t_master *master);
void		pa_operation(t_master *master);
int			medium_sort(t_master *master);
int			rank_stack(int *stack, int size);

#endif
