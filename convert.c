/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:29:48 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 15:56:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad(t_spec spec, int *count, size_t len, char c)
{
	if (spec.width > len)
	{
		ft_pad_fd(c, spec.width - len, 1);
		*count += spec.width - len;
	}
}

void	format_print(t_spec spec, char *str, int *count)
{
	size_t	len;

	len = ft_strlen(str);
	if (!spec.minus && !spec.zero)
	{
		pad(spec, count, len, ' ');
	}
	ft_putstr_fd(str, 1);
	*count += len;
	if (spec.minus)
		pad(spec, count, len, ' ');
}

void	convert(t_spec spec, va_list *args, int *count)
{
	if (spec.type == 'c')
		convert_char(args, count, spec);
	else if (spec.type == 's')
		convert_string(args, count, spec);
	else if (spec.type == 'p')
		convert_pointer(args, count, spec);
	else if (spec.type == 'd' || spec.type == 'i')
		convert_int(args, count, spec);
	else if (spec.type == 'u')
		convert_unsigned(args, count, spec);
	else if (spec.type == 'x')
		convert_hex(args, count, spec, "0123456789abcdef");
	else if (spec.type == 'X')
		convert_hex(args, count, spec, "0123456789ABCDEF");
	else if (spec.type == '%')
		convert_percent_literal(count);
}
