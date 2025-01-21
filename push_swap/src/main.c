#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a, b;

    if (argc < 2)
    {
        ft_printf("\033[33m⚠️ No input provided.\033[0m\n");
        return (0);
    }
    if (!parse_input(&a, argv))
    {
        ft_printf("\033[31m❌ Error: Invalid input.\033[0m\n");
        return (1);
    }
    init_stack(&b);

    // Debug: Print parsed stack
    // ft_printf("Parsed stack A: ");
    // print_stack(&a);

    if (a.size == 2)
        sort_two(&a);
    else if (a.size == 3)
        sort_three(&a);
    else if (a.size == 4 || a.size == 5)
        sort_four_five(&a, &b);
    else
        radix_sort(&a, &b);
    

    // ft_printf("Final sorted stack A: ");
    // print_stack(&a);

    free_stack(&a);
    free_stack(&b);
    return (0);
}
