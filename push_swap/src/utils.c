/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:55 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:36:06 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

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

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void	quick_sort_array(int *arr, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quick_sort_array(arr, low, pivot_index - 1);
		quick_sort_array(arr, pivot_index + 1, high);
	}
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
