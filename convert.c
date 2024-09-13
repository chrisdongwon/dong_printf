/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 23:38:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(t_spec spec, va_list *args, int *count)
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
