/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:29:48 by cwon              #+#    #+#             */
/*   Updated: 2024/09/21 17:56:03 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_print(t_spec spec, char *str, int *count)
{
	char	*space_pad;
	size_t	space_len;
	size_t	len;

	len = ft_strlen(str);
	space_len = 0;
	if (spec.width > len)
		space_len = spec.width - len;
	space_pad = pad_string(space_len, ' ');
	if (!spec.minus)
	{
		ft_putstr_fd(space_pad, 1);
		*count += space_len;
	}
	ft_putstr_fd(str, 1);
	*count += len;
	if (spec.minus)
	{
		ft_putstr_fd(space_pad, 1);
		*count += space_len;
	}
	free(space_pad);
	free(str);
}

void	convert(t_spec spec, va_list *args, int *count)
{
	if (spec.type == 'c')
		convert_char(args, count, spec);
	else if (spec.type == 's')
		convert_string(args, count, spec);
	else if (spec.type == 'd' || spec.type == 'i')
		convert_int(args, count, spec);
	else if (spec.type == 'u')
		convert_unsigned(args, count, spec);
	else if (spec.type == 'x')
		convert_hex(args, count, spec, "0123456789abcdef");
	else if (spec.type == 'X')
		convert_hex(args, count, spec, "0123456789ABCDEF");
	else if (spec.type == 'p')
		convert_pointer(args, count, spec);
	else if (spec.type == '%')
		convert_percent_literal(count);
}
