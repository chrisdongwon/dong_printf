/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:51:00 by cwon              #+#    #+#             */
/*   Updated: 2024/09/11 23:05:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_member(const char c, const char *arr)
{
	while (arr && *arr)
	{
		if (*(arr++) == c)
			return (1);
	}
	return (0);
}

static char	*extract_spec(const char **str)
{
	const char	*next;
	char		*result;

	next = (*str) + 1;
	if (is_member(*next, "cspdiuxX%"))
	{
		result = (char*)malloc(2);
		result[0] = *next;
		result[1] = 0;
		*str += 2;
	}
	else // what about spaces after percent? i.e. bonus material
	{
		result = (char *)malloc(0);
		*str += 1;
	}
	return (result);
}

static void	parse(const char *format, va_list *args, int *count)
{
	char	*spec;
	
	while (format && *format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*(format++), 1);
			(*count)++;
		}
		else
		{
			spec = extract_spec(&format);
			convert(spec, args, count);
			free(spec);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	
	count = 0;
	va_start(args, format);
	parse(format, &args, &count);
	va_end(args);
	return (count);
}
