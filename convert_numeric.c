/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:17 by cwon              #+#    #+#             */
/*   Updated: 2024/09/19 13:51:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pad_sign(char **str, const char c)
{
	char	*sign;
	char	*result;

	sign = (char *)malloc(2);
	sign[0] = c;
	sign[1] = 0;
	result = ft_strjoin(sign, *str);
	free(*str);
	free(sign);
	*str = result;
}

void	convert_int(va_list *args, int *count, t_spec spec)
{
	char	*str;
	int		val;

	val = va_arg(*args, int);
	str = ft_itoa(val);
	if (spec.dot)
	{
		spec.zero = 1;
		spec.width = spec.precision;
		if (str[0] == '-')
			spec.width++;
	}
	if (spec.zero && spec.width > ft_strlen(str))
		pad_zero(spec, &str);
	if (val >= 0 && (spec.plus || spec.space))
	{
		if (spec.plus)
			pad_sign(&str, '+');
		else if (spec.space)
			pad_sign(&str, ' ');
	}
	format_print(spec, str, count);
	free(str);
}

void	convert_unsigned(va_list *args, int *count, t_spec spec)
{
	char	*str;

	str = ft_utoa(va_arg(*args, unsigned int));
	if (spec.dot)
	{
		spec.zero = 1;
		spec.width = spec.precision;
	}
	if (spec.zero && spec.width > ft_strlen(str))
		pad_zero(spec, &str);
	format_print(spec, str, count);
	free(str);
}
