#include "push_swap.h"

void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

// Push to the bottom of the stack
void push_bottom(t_stack *stack, int value)
{
    t_node *new_node;
    t_node *current;

    new_node = (t_node *)ft_calloc(1, sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;

    if (!stack->top)
        stack->top = new_node;
    else
    {
        current = stack->top;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
    stack->size++;
}

// Parse and validate input arguments
int parse_input(t_stack *stack, char **argv)
{
    int i;
    int value;

    init_stack(stack);
    i = 1;
    while (argv[i])
    {
        if (!is_valid_number(argv[i]))
        {
            free_stack(stack);
            return (0); // Invalid input
        }
        value = ft_atoi(argv[i]);
        if (contains_duplicate(stack, value))
        {
            free_stack(stack);
            return (0); // Duplicate found
        }
        push_bottom(stack, value); // Push to the bottom to preserve input order
        i++;
    }
    return (1); // Valid input
}

// Check if the string is a valid integer
int is_valid_number(char *str)
{
    int i;

    if (!str || !*str)
        return (0); // Empty string is invalid

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0); // Not a digit
        i++;
    }
    return (1); // Valid number
}

// Check for duplicates in the stack
int contains_duplicate(t_stack *stack, int value)
{
    t_node *current;

    current = stack->top;
    while (current)
    {
        if (current->value == value)
            return (1); // Duplicate found
        current = current->next;
    }
    return (0); // No duplicates
}
