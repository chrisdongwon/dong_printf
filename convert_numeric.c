/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:17 by cwon              #+#    #+#             */
/*   Updated: 2024/09/16 06:42:45 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_int(va_list *args, int *count, t_spec spec)
{
	char	*str;
	int		val;

	val = va_arg(*args, int);
	str = ft_itoa(val);
	if (spec.zero && spec.width > ft_strlen(str))
		pad_zero(spec, &str);	
	if (val >= 0 && (spec.plus || spec.space))
	{
		if (spec.plus)
			ft_putchar_fd('+', 1);
		else if (spec.space)
			ft_putchar_fd(' ', 1);
		(*count)++;
	}
	format_print(spec, str, count);
	free(str);
}

void	convert_unsigned(va_list *args, int *count, t_spec spec)
{
	char	*str;

	str = ft_utoa(va_arg(*args, unsigned int));
	if (spec.zero && spec.width > ft_strlen(str))
		pad_zero(spec, &str);
	format_print(spec, str, count);
	free(str);
}
