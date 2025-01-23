/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:11 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:07:12 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		swap(a, "sa");
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		swap(a, "sa");
	else if (first > second && second > third)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (first > second && second < third && first > third)
		rotate(a, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	else if (first < second && second > third && first > third)
		reverse_rotate(a, "rra");
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	sort_three(a);
	push(b, a, "pa");
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_to_b(a, b);
	push_smallest_to_b(a, b);
	sort_three(a);
	push(b, a, "pa");
	push(b, a, "pa");
}

void	sort_four_five(t_stack *a, t_stack *b)
{
	if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}
