#include "push_swap.h"

// Get the maximum value in the stack
int get_max_value(t_stack *stack)
{
    t_node *current;
    int max;

    current = stack->top;
    max = current->value;
    while (current)
    {
        max = (current->value > max) ? current->value : max;
        current = current->next;
    }
    return (max);
}

// Get the number of bits needed to represent the maximum value
int get_max_bits(t_stack *stack)
{
    int max;
    int bits;

    max = get_max_value(stack);
    bits = 0;
    while (max)
    {
        max >>= 1;
        bits++;
    }
    return (bits);
}

// Perform optimized Radix Sort

void radix_sort(t_stack *a, t_stack *b)
{
    if (a->size > 100)
        chunk_sort(a, b, 20); // Split into chunks for larger inputs
    else
    {
        int max_bits;
        int i, j, size, value;

        max_bits = get_max_bits(a);
        i = 0;
        while (i < max_bits)
        {
            j = 0;
            size = a->size;
            while (j < size)
            {
                value = a->top->value;
                if ((value >> i) & 1)
                    rotate(a, "ra");
                else
                    push(a, b, "pb");
                j++;
            }
            while (b->size > 0)
                push(b, a, "pa");
            i++;
        }
    }
}

void chunk_sort(t_stack *a, t_stack *b, int chunk_size)
{
    int min;
    int max;

    min = 0;
    max = chunk_size - 1;
    while (min < a->size)
    {
        push_chunk_to_b(a, b, min, max);
        while (b->size > 0)
            push(b, a, "pa");
        min += chunk_size;
        max += chunk_size;
    }
}
