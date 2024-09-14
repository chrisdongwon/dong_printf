/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:51:00 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 00:22:54 by cwon             ###   ########.fr       */
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

static void	convert(t_spec spec, va_list *args, int *count)
{
	if (spec.type == 'c')
		convert_char(args, count);
	else if (spec.type == 's')
		convert_string(args, count);
	else if (spec.type == 'p')
		convert_pointer(args, count);
	else if (spec.type == 'd' || spec.type == 'i')
		convert_int(args, count);
	else if (spec.type == 'u')
		convert_unsigned(args, count);
	else if (spec.type == 'x')
		convert_hex(args, count, spec.pound, "0123456789abcdef");
	else if (spec.type == 'X')
		convert_hex(args, count, spec.pound, "0123456789ABCDEF");
	else if (spec.type == '%')
		convert_percent_literal(count);
}

static void	parse(const char *format, va_list *args, int *count)
{
	t_spec	spec;
	
	init_spec(&spec);
	while (format && *format)
	{
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
