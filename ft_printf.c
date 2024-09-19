/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:51:00 by cwon              #+#    #+#             */
/*   Updated: 2024/09/19 16:56:18 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_spec(t_spec *spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->dot = 0;
	spec->pound = 0;
	spec->space = 0;
	spec->plus = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->type = 0;
}

static void	parse(const char *format, va_list *args, int *count)
{
	t_spec	spec;

	while (format && *format)
	{
		init_spec(&spec);
		if (*format != '%')
		{
			ft_putchar_fd(*(format++), 1);
			(*count)++;
		}
		else
		{
			format++;
			extract(&format, &spec);
			convert(spec, args, count);
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
