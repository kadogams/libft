# Push_swap

## Description

A project about sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions (full project instructions available [here](https://github.com/kadogams/42_projects/tree/master/push_swap/resources)).

The project consists of two programs:
- checker: takes integer arguments and reads instructions on the standard output, and checks if they are sorted.
- push_swap: calculates and displays on the standard output the lowest possible instructions to sort the received integer arguments, using Push_swap instruction language.

### Sorting program flow

- check command line arguments.
- quicksort on an int array to have a presorted array, in order to find the median values of the partitions faster during the main algorithm.
- backtracking on the whole set of values to see if can be solved in 8 or less moves.
- start a divide and conquer algorithm based on medians, with a backtracking when a partition contains 5 or less elements, in order to sort them with the minimum possible operations.

### Push_swap instruction language

>__sa__ : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).  
__sb__ : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).  
__ss__ : sa and sb at the same time.  
__pa__ : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
__pb__ : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
__ra__ : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
__rb__ : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
__rr__ : ra and rb at the same time.  
__rra__ : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.  
__rrb__ : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.  
__rrr__ : rra and rrb at the same time.

## Usage

You may compile the binaries by running ```make```.

### checker

```bash
./push_swap [-v] integer list
```

### push_swap

```bash
./push_swap integer list
```
