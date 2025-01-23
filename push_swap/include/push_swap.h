/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:37:42 by lucguima          #+#    #+#             */
/*   Updated: 2025/01/23 18:37:43 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/includes/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// Stack operations
void				swap(t_stack *stack, char *operation);
void				push(t_stack *src, t_stack *dest, char *operation);
void				rotate(t_stack *stack, char *operation);
void				reverse_rotate(t_stack *stack, char *operation);

// Parsing functions
void				init_stack(t_stack *stack);
int					validate_and_push(t_stack *stack, char *num);
int					parse_and_split(t_stack *stack, char *input);
int					parse_input(t_stack *stack, char **argv);
int					is_valid_number(char *str);
int					contains_duplicate(t_stack *stack, int value);

// Radix sort
void				radix_sort(t_stack *a, t_stack *b);
int					*extract_values_to_array(t_stack *stack);
void				assign_indexes(t_stack *stack, int *values, int size);
void				map_values_to_indexes(t_stack *stack);

// Sorting logic
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);
void				sort_four_five(t_stack *a, t_stack *b);

// Utils
void				free_stack(t_stack *stack);
int					partition(int *arr, int low, int high);
void				quick_sort_array(int *arr, int low, int high);

// Utils_2
void				move_smallest_to_top(t_stack *stack, int index);
void				push_smallest_to_b(t_stack *a, t_stack *b);
int					find_smallest_index(t_stack *stack);
void				push_bottom(t_stack *stack, int value);
void				free_split(char **split);

#endif
