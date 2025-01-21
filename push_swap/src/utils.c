#include "push_swap.h"

// Push a new value onto the stack
void push_stack(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = (t_node *)ft_calloc(1, sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    // Debug: Print stack state after each push
    ft_printf("Pushed %d to stack. Current stack: ", value);
    print_stack(stack);
}

// Free all nodes in the stack
void free_stack(t_stack *stack)
{
    t_node *current;
    t_node *tmp;

    current = stack->top;
    while (current)
    {
        tmp = current->next;
        ft_bzero(current, sizeof(t_node));
        free(current);
        current = tmp;
    }
    stack->top = NULL;
    stack->size = 0;
}

// Print the stack's contents
void print_stack(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        ft_putnbr_fd(current->value, 1);
        ft_putchar_fd(' ', 1);
        current = current->next;
    }
    ft_putchar_fd('\n', 1);
}

void push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
    int i;
    int size;

    size = a->size;
    i = 0;
    while (i < size)
    {
        if (a->top->value >= min && a->top->value <= max)
            push(a, b, "pb");
        else
            rotate(a, "ra");
        i++;
    }
}
void merge_back_to_a(t_stack *a, t_stack *b)
{
    // As long as B has elements, push them back to A
    while (b->size > 0)
    {
        // Possibly rotate A or B to maintain correct overall order
        // or just push if your approach already ensures correct order
        push(b, a, "pa");
    }

    // Maybe rotate A so the smallest is on top, if that's your final convention
    int smallest = find_smallest(a);
    while (a->top->value != smallest)
        rotate(a, "ra");
}




void sort_small_stack_b(t_stack *b)
{
    if (b->size == 2 && b->top->value < b->top->next->value)
        swap(b, "sb");
    else if (b->size == 3)
    {
        if (b->top->value < b->top->next->value)
            swap(b, "sb");
        reverse_rotate(b, "rrb");
        if (b->top->value < b->top->next->value)
            swap(b, "sb");
    }
}

int find_smallest(t_stack *stack)
{
    t_node *current;
    int smallest;

    current = stack->top;
    smallest = current->value;
    while (current)
    {
        if (current->value < smallest)
            smallest = current->value;
        current = current->next;
    }
    return (smallest);
}

int find_largest(t_stack *stack)
{
    t_node *current;
    int largest;

    current = stack->top;
    largest = current->value;
    while (current)
    {
        if (current->value > largest)
            largest = current->value;
        current = current->next;
    }
    return (largest);
}

int find_insert_position(t_stack *a, int value)
{
    t_node *current;
    int     i;

    // Edge case: if A is empty, insertion index is 0
    if (a->size == 0)
        return (0);

    current = a->top;
    i = 0;
    // Traverse the stack from top to bottom
    while (i < a->size)
    {
        // If we find a node whose value is greater than 'value',
        // that's where 'value' should go.
        if (current->value > value)
            return (i);
        current = current->next;
        i++;
    }
    // If we never found a bigger value, 'value' is >= all elements in A
    // so we insert at the bottom (index = size).
    return (a->size);
}