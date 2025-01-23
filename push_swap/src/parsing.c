/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:06:37 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:06:38 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

int	validate_and_push(t_stack *stack, char *num)
{
	int	value;

	if (!is_valid_number(num))
		return (0);
	value = ft_atoi(num);
	if (contains_duplicate(stack, value))
		return (0);
	push_bottom(stack, value);
	return (1);
}

int	parse_and_split(t_stack *stack, char *input)
{
	char	**numbers;
	int		i;

	numbers = ft_split(input, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!validate_and_push(stack, numbers[i]))
		{
			free_split(numbers);
			return (0);
		}
		i++;
	}
	free_split(numbers);
	return (1);
}

int	parse_input(t_stack *stack, char **argv)
{
	char	*trimmed_input;

	init_stack(stack);
	if (!argv[1] || argv[1][0] == '\0')
		return (0);
	trimmed_input = ft_strtrim(argv[1], " ");
	if (!trimmed_input || ft_strlen(trimmed_input) == 0)
	{
		free(trimmed_input);
		return (0);
	}
	free(trimmed_input);
	if (!parse_and_split(stack, argv[1]))
		return (0);
	return (1);
}

int	contains_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
