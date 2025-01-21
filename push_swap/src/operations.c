#include "push_swap.h"

// Swap the first two elements of a stack
void swap(t_stack *stack, char *operation)
{
    t_node *first;
    t_node *second;

    if (!stack || stack->size < 2)
        return;
    first = stack->top;
    second = first->next;

    first->next = second->next;
    second->next = first;
    stack->top = second;

    ft_printf("%s\n", operation);
}
// Push the top element of src to dest
void push(t_stack *src, t_stack *dest, char *operation)
{
    t_node *temp;

    if (!src || src->size == 0)
        return;
    temp = src->top;
    src->top = temp->next;
    src->size--;

    temp->next = dest->top;
    dest->top = temp;
    dest->size++;

    ft_printf("%s\n", operation); // Print operation
}

// Rotate a stack (first element becomes last)
void rotate(t_stack *stack, char *operation)
{
    t_node *first;
    t_node *last;

    if (!stack || stack->size < 2)
        return;
    first = stack->top;
    stack->top = first->next;

    last = stack->top;
    while (last->next)
        last = last->next;
    last->next = first;
    first->next = NULL;

    ft_printf("%s\n", operation); // Print operation
}

// Reverse rotate a stack (last element becomes first)
void reverse_rotate(t_stack *stack, char *operation)
{
    t_node *prev;
    t_node *last;

    if (!stack || stack->size < 2)
        return;
    last = stack->top;
    prev = NULL;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;

    ft_printf("%s\n", operation); // Print operation
}
