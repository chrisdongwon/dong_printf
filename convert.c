/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 01:29:48 by cwon              #+#    #+#             */
/*   Updated: 2024/09/16 06:42:52 by cwon             ###   ########.fr       */
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

	zero_len = spec.width - ft_strlen(*str);
	zero_str = (char *)malloc(zero_len + 1);
	zero_str = (char *)ft_memset(zero_str, '0', zero_len);
	zero_str[zero_len] = 0;
	result = ft_strjoin(zero_str, *str);
	if (*str[0] == '-')
		swap(result, 0, zero_len);
	free(zero_str);
	free(*str);
	*str = result;
}

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
