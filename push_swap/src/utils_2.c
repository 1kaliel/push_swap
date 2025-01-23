/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:36 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:34:34 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move_smallest_to_top(t_stack *stack, int index)
{
	int	i;

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

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	smallest_index;

	smallest_index = find_smallest_index(a);
	move_smallest_to_top(a, smallest_index);
	push(a, b, "pb");
}

int	find_smallest_index(t_stack *stack)
{
	t_node	*current;
	int		smallest;
	int		index;
	int		i;

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

void	push_bottom(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return ;
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
