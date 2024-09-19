/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:29:48 by cwon              #+#    #+#             */
/*   Updated: 2024/09/19 16:55:12 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	swap(char *str, size_t i, size_t j)
{
	char	temp;

	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void	pad_zero(t_spec spec, char **str)
{
	char	*result;
	char	*zero_str;
	size_t	zero_len;
	size_t	len;

	len = ft_strlen(*str);
	zero_len = 0;
	if (spec.width > len)
		zero_len = spec.width - len;
	zero_str = pad_string(zero_len, '0');
	result = ft_strjoin(zero_str, *str);
	if (*str[0] == '-')
		swap(result, 0, zero_len);
	free(zero_str);
	free(*str);
	*str = result;
}

char	*pad_string(size_t n, const char c)
{
	char	*str;

	str = (char *)malloc(n + 1);
	str = (char *)ft_memset(str, c, n);
	str[n] = 0;
	return (str);
}

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
