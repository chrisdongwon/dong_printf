/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:17 by cwon              #+#    #+#             */
/*   Updated: 2024/09/22 10:40:26 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pad_sign(t_spec spec, char **str)
{
	char	*sign;
	char	*result;

	if ((spec.space || spec.plus) && *str[0] != '-')
	{
		sign = (char *)malloc(2);
		if (spec.space)
			sign[0] = ' ';
		else if (spec.plus)
			sign[0] = '+';
		sign[1] = 0;
		result = ft_strjoin(sign, *str);
		free(*str);
		free(sign);
		*str = result;
	}
}

void	convert_int(va_list *args, int *count, t_spec spec)
{
	char	*str;
	size_t	len;
	size_t	digit_len;

	str = ft_itoa(va_arg(*args, int));
	len = ft_strlen(str);
	digit_len = len;
	if (str[0] == '-')
		digit_len--;
	if (spec.dot && !spec.precision && str[0] == '0')
	{
		free(str);
		str = ft_strdup("");
	}
	if (spec.dot && spec.precision < 0)
		spec.dot = 0;
	if (spec.dot && spec.zero)
		spec.zero = 0;
	if (spec.dot && spec.precision > (int)digit_len)
		pad_zero(&str, spec.precision - digit_len);
	else if (spec.zero && !spec.dot && spec.width > len)
		pad_zero(&str, spec.width - len);
	pad_sign(spec, &str);
	format_print(spec, str, count);
}

void	convert_unsigned(va_list *args, int *count, t_spec spec)
{
	char	*str;
	size_t	len;

	str = ft_utoa(va_arg(*args, unsigned int));
	len = ft_strlen(str);
	if (spec.dot && spec.precision <= 0)
	{
		if (str[0] == '0')
		{
			free(str);
			str = ft_strdup("");
		}
		else
			spec.dot = 0;
	}
	if (spec.dot && spec.precision > (int)len)
		pad_zero(&str, spec.precision - len);
	else if (spec.zero && !spec.dot && spec.width > len)
		pad_zero(&str, spec.width - len);
	format_print(spec, str, count);
}
