#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/includes/ft_printf.h"

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

// Parsing functions
void push_bottom(t_stack *stack, int value);
int parse_input(t_stack *stack, char **argv);
int is_valid_number(char *str);
int contains_duplicate(t_stack *stack, int value);
void init_stack(t_stack *stack);

// Stack management
void push_stack(t_stack *stack, int value);
void free_stack(t_stack *stack);
void print_stack(t_stack *stack);

// Stack operations
void swap(t_stack *stack, char *operation);
void push(t_stack *src, t_stack *dest, char *operation);
void rotate(t_stack *stack, char *operation);
void reverse_rotate(t_stack *stack, char *operation);

// Sorting logic
void sort_two(t_stack *a);
void sort_three(t_stack *a);
int find_smallest_index(t_stack *stack);
void move_smallest_to_top(t_stack *stack, int index);
void push_smallest_to_b(t_stack *a, t_stack *b);
void sort_four(t_stack *a, t_stack *b);
void sort_five(t_stack *a, t_stack *b);
void sort_four_five(t_stack *a, t_stack *b);
void push_chunk_to_b(t_stack *a, t_stack *b, int min, int max);


// Radix sort
void radix_sort(t_stack *a, t_stack *b);
void chunk_sort(t_stack *a, t_stack *b, int chunk_size);

// Quick sort
void quick_sort(t_stack *a, t_stack *b);
int find_median(t_stack *stack);
void partition(t_stack *a, t_stack *b, int pivot);
void quick_sort_array(int *arr, int low, int high);

void sort_small_stack_b(t_stack *b);
void merge_back_to_a(t_stack *a, t_stack *b);
int find_smallest(t_stack *stack);

int find_largest(t_stack *stack);

int find_insert_position(t_stack *a, int value);





#endif
