/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_literal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:17:39 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 13:52:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(va_list *args, int *count, t_spec spec)
{	
	if (!spec.minus)
		pad(spec, count, 1, ' ');
	ft_putchar_fd(va_arg(*args, int), 1);
	*count += 1;
	if (spec.minus)
		pad(spec, count, 1, ' ');
}

void	convert_string(va_list *args, int *count, t_spec spec)
{
	char	*str;
	
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	format_print(spec, str, count);
}

void	convert_percent_literal(int *count)
{
	ft_putchar_fd('%', 1);
	*count += 1;
}
