/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucguima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:21:44 by lucguima          #+#    #+#             */
/*   Updated: 2024/09/06 15:54:11 by lucguima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	is_within_int_range(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		str++;
	}
	return (1);
}

static size_t	c_words(const char *s, char c)
{
	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static char	*w_dup(const char **s, char c)
{
	char	*word;
	size_t	len;
	char	*temp;

	len = 0;
	while (**s && **s != c)
	{
		len++;
		(*s)++;
	}
	temp = ft_substr(*s - len, 0, len);
	if (!is_within_int_range(temp))
	{
		free(temp);
		return (NULL);
	}
	word = temp;
	return (word);
}

static char	**free_split(char **split, size_t i)
{
	while (i > 0)
		free(split[--i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = c_words(s, c);
	split = ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			split[i] = w_dup(&s, c);
			if (!split[i])
				return (free_split(split, i));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
