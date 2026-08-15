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

### Architecture

The program is built around a central __master structure__ that holds all important values:

``` c
typedef struct s_master
{
t_strategy strat;
    t_op       op_counter;
    t_flags    flags;
    int        *stack_a;
    int        *stack_b;
    int        size_a;
    int        size_b;
    double     disorder;
    char       **args;
    int        split;
}              t_master;
```

This structure sggregates the two stacks, operation counters, flags, chosen strategy, and parsed arguments. This design allow all functions to access and modify the program state through a single pointer, eliminating the need for excessive parameter passing.

### Algorithms

* __Simple - O(n2)__:
  * It was used a selection sort, where it repeteadly finds the minimum element in _stack_a_, rotates it to the top, and pushes it to _stack_b_. Once _stack_a_ is empty, all elementes are pushed back to _stack_a_ in sorted order.

* __Medium - O(n√n)__:
  * It was used a chunk sort strategy. The stack is first ranked into normalized indices, then divided into chunks of size approximately √n. Elements within the current rank range are rotated to the top of _stack_a_ and pused to _stack_b_, proceeding from the lowest chunk to the highest. Once _stack_a_ is empty, elements are pushed back in reverse chunk order (for each chunk, the maximum value is retrieved first), which builds _stack_a_ in ascending order from top to bottom.

* __Complex - O(n log n)__:
  * It was used a LSD (Least Significant Digit) radix sort. The stack is first ranked into normalized indices from 0 to (size - 1). Then, for each bit position from least to most significant, a pass is performed: every element in _stack_a_ with the current bit set to 0 is pushed to _stack_b_, while elements with the bit set to 1 are rotated withing _stack_a_. After processing all elements of that bit position, everything in _stack_b_ is pushed back to _stack_a_. The process repeats for each bit until the entire stack is sorted in ascending order.

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

Optional flags are:

* --bench
* --simple
* --medium
* --complex
* --adaptive

They must be used before arguments. You may not use more than one strategy flag (simple medium complex adaptive).

```bash
./push_swap <optional flags> <integer arguments> (or <"integer arguments">)
```

## Resources

"__man__" used on Linux terminal and internet forums such as Stack Overflow were the primary sources of information.

AI was used as a secondary learning tool.
