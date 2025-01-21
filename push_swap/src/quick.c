#include "push_swap.h"

// Partition stack `a` into two parts using a pivot
void partition(t_stack *a, t_stack *b, int pivot)
{
    int original_size = a->size;
    for (int i = 0; i < original_size; i++)
    {
        if (a->top->value < pivot)
            push(a, b, "pb");   // push smaller elements to B
        else
            rotate(a, "ra");    // keep bigger elements in A
    }
}

// Find the median value for pivot selection
int find_median(t_stack *stack)
{
    int *values;
    int i;
    t_node *current;
    int median;

    values = ft_calloc(stack->size, sizeof(int));
    if (!values)
        return (0);

    current = stack->top;
    i = 0;
    while (current)
    {
        values[i++] = current->value;
        current = current->next;
    }

    quick_sort_array(values, 0, stack->size - 1);
    median = values[stack->size / 2];
    free(values);
    return (median);
}

void quick_sort(t_stack *a, t_stack *b)
{
    if (a->size <= 3)
    {
        // Handle small stack (e.g., sort_two or sort_three on A)
        return;
    }

    // 1) Choose pivot (e.g., median)
    int pivot = find_median(a);

    // 2) Partition: 
    //    push all elements < pivot to B, or all > pivot, whichever approach you prefer
    partition(a, b, pivot);

    // 3) Recursively sort the half that remains in A
    quick_sort(a, b);

    // 4) Recursively sort the half that’s now in B
    quick_sort(b, a);

    // 5) Merge the two sorted halves. 
    //    If your approach is “all smaller in B,” you want to push them back in ascending order.
    merge_back_to_a(a, b);
}


// Quick Sort for an array (helper for `find_median`)
void quick_sort_array(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;

    if (low < high)
    {
        pivot = arr[high];
        i = low - 1;
        j = low;
        while (j < high)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quick_sort_array(arr, low, i);
        quick_sort_array(arr, i + 2, high);
    }
}
