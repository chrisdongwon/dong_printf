/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:15:03 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 00:23:08 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(char *spec, va_list *args, int *count)
{
	if (spec[0] == 'c')
		convert_char(args, count);
	else if (spec[0] == 's')
		convert_string(args, count);
	else if (spec[0] == 'p')
		return; // stub
	else if (spec[0] == 'd' || spec[0] == 'i')
		convert_int(args, count);
	else if (spec[0] == 'u')
		convert_unsigned(args, count);
	else if (spec[0] == 'x')
		convert_hex(args, count, "0123456789abcdef");
	else if (spec[0] == 'X')
		convert_hex(args, count, "0123456789ABCDEF");
	else if (spec[0] == '%')
		convert_percent_literal(count);
}
