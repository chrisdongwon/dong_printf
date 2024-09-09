/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:17:00 by cwon              #+#    #+#             */
/*   Updated: 2024/09/08 17:23:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	current;
	size_t	prev;

	count = 0;
	current = 0;
	prev = 0;
	while (s && s[current])
	{
		if (!current && s[current] != c)
			count++;
		else if (s[prev] == c && s[current] != c)
			count++;
		prev = current;
		current++;
	}
	return (count);
}

static char	*extract(const char *s, char c, size_t *start)
{
	char	*result;
	size_t	end;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	result = ft_substr(s, *start, end - *start);
	*start = end;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	count;
	size_t	i;
	size_t	start;

	count = word_count(s, c);
	i = 0;
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (result)
	{
		start = 0;
		while (i < count)
			result[i++] = extract(s, c, &start);
		result[i] = 0;
	}
	return (result);
}
