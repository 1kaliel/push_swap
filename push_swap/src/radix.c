/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:06:53 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:06:55 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	max_bits;
	int	bit_index;

	map_values_to_indexes(a);
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		bit_index = 0;
		while (bit_index++ < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				push(a, b, "pb");
			else
				rotate(a, "ra");
		}
		while (b->size > 0)
			push(b, a, "pa");
	}
}

int	*extract_values_to_array(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		i;

	values = ft_calloc(stack->size, sizeof(int));
	if (!values)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	return (values);
}

void	assign_indexes(t_stack *stack, int *values, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == values[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	map_values_to_indexes(t_stack *stack)
{
	int	*values;

	if (!stack || stack->size == 0)
		return ;
	values = extract_values_to_array(stack);
	if (!values)
		return ;
	quick_sort_array(values, 0, stack->size - 1);
	assign_indexes(stack, values, stack->size);
	free(values);
}
