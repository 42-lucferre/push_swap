# _This project has been created as part of the 42 curriculum by jcorrea, lucferre_

## Description

This project sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions.

It sorts a stack of integers using two stacks (A and B) and a limited set of operations, included below. The goal is to sort stack A in ascending order with the minimum number of operations.

The program receives a list of integers as arguments, validates them, and outputs the sequence of operations needed to sort them.

* __sa__ (swap a):
  * Swap the first two elements at the top of stack _a_.
  * Do nothing if there is only one or no elements.

* __sb__ (swap b):
  * Swap the first two elements at the top of stack _b_.
  * Do nothing if there is only one or no elements.

* __ss__ (swap both):
  * sa and sb at the same time.

* __pa__ (push a):
  * Take the first element at the top of _b_ and put it at the top of _a_.
  * Do nothing if _b_ is empty.

* __pb__ (push b):
  * Take the first element at the top of _a_ and put it at the top of _b_.
  * Do nothing if _a_ is empty.

* __ra__ (rotate a):
  * Shift up all elements of stack _a_ by one.
  * The first element becomes the last one.

* __rb__ (rotate b):
  * Shift up all elements of stack _b_ by one.
  * The first element becomes the last one.

* __rr__ (rotate both):
  * ra and rb at the same time.

* __rra__ (reverse rotate a):
  * Shift down all elements of stack _a_ by one.
  * The last element becomes the first one.

* __rrb__ (reverse rotate b):
  * Shift down all elements of stack _b_ by one.
  * The last element becomes the first one.

* __rrr__ (reverse rotate both):
  * rra and rrb at the same time.

## Details

### Functions

t_op;
t_flags
t_strategy
t_master

// Flags & errors
int			error_check(t_master *master);
int			rep_check(int size, char **args);
int			flag_check(t_master *master);
int			flag_value(t_flags *flag, char *arg);
int			space_check(t_master *master);
int			int_check(int size, char **args);
void		bench_printer(t_master *master);
void		disorder_printer(t_master *master);
void		flag_printer(t_master *master);
void		strat_printer(t_master *master);
void		op_counter_printer(t_op op_counter);

// Initializers & free
void		init_flags(t_flags *flags);
t_master	*init_master(int size, char **args);
void		init_counter(t_op *op_counter);
void		free_all(t_master *master);

// Operators

int			main(int argc, char **argv);
int			stack_creator(t_master *master);
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

## Instructions

To compile this program, run:

```bash
make
```

or

```bash
make all
```

* Compiles everything with __libft.a__ and creates __push_swap__ executable.

***

```bash
make clean
```

* Removes object (__.o__) files;
* Removes precompiled headers (__.gch__).

***

```bash
make fclean
```

* Calls _make clean_;
* Removes __libft.a__.
* Removes __push_swap__.

***

```bash
make re
```

* Calls _make fclean_;
* Calls _make all_.

***

Included flags are:

--bench
--simple
--medium
--complex
--adaptive

They must be used before arguments. You may not use more than one strategy flag (simple medium complex adaptive)

```bash
cc <your_file.c> -I./Libft -L./Libft -lft -o <output_name>
```

## Resources

"__man__" was the primary source of information, used on Linux terminal.

AI was used as a secondary learning tool.
