#include "push_swap.h"

// Sort 2 elements in stack A
void sort_two(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        swap(a, "sa");
}


// Sort 3 elements in stack A
void sort_three(t_stack *a)
{
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        swap(a, "sa"); // Case: 2 1 3
    else if (first > second && second > third)
    {
        swap(a, "sa");
        reverse_rotate(a, "rra"); // Case: 3 2 1
    }
    else if (first > second && second < third && first > third)
        rotate(a, "ra"); // Case: 3 1 2
    else if (first < second && second > third && first < third)
    {
        swap(a, "sa");
        rotate(a, "ra"); // Case: 1 3 2
    }
    else if (first < second && second > third && first > third)
        reverse_rotate(a, "rra"); // Case: 2 3 1
}

// Find the index of the smallest element in the stack
int find_smallest_index(t_stack *stack)
{
    t_node *current;
    int smallest;
    int index;
    int i;

    current = stack->top;
    smallest = current->value;
    index = 0;
    i = 0;
    while (current)
    {
        if (current->value < smallest)
        {
            smallest = current->value;
            index = i;
        }
        current = current->next;
        i++;
    }
    return (index);
}

// Move the smallest element to the top of the stack
void move_smallest_to_top(t_stack *stack, int index)
{
    int i;

    if (index <= stack->size / 2)
    {
        i = 0;
        while (i < index)
        {
            rotate(stack, "ra");
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < stack->size - index)
        {
            reverse_rotate(stack, "rra");
            i++;
        }
    }
}

// Push the smallest element in stack A to stack B
void push_smallest_to_b(t_stack *a, t_stack *b)
{
    int smallest_index;

    smallest_index = find_smallest_index(a);
    move_smallest_to_top(a, smallest_index);
    push(a, b, "pb");
}


void sort_four(t_stack *a, t_stack *b)
{
    push_smallest_to_b(a, b);
    sort_three(a);
    push(b, a, "pa");
}

void sort_five(t_stack *a, t_stack *b)
{
    push_smallest_to_b(a, b);
    push_smallest_to_b(a, b);
    sort_three(a);
    push(b, a, "pa");
    push(b, a, "pa");
}

void sort_four_five(t_stack *a, t_stack *b)
{
    if (a->size == 4)
        sort_four(a, b);
    else if (a->size == 5)
        sort_five(a, b);
}
