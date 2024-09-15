/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:21:21 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 14:49:47 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_length(unsigned int n)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	*to_hex_string(unsigned int n, t_spec spec, const char *hex)
{
	size_t	len;
	char	*result;

	len = hex_length(n);
	if (spec.pound && n)
		len += 2;
	result = (char *)malloc(len + 1);
	result[len--] = 0;
	if (!n)
		result[0] = '0';
	while (n)
	{
		result[len--] = hex[n % 16];
		n /= 16;
	}
	if (spec.pound && n)
	{
		if (hex[10] == 'a')
			result[len--] = 'x';
		else
			result[len--] = 'X';
		result[len] = '0';
	}
	return (result);
}

void	convert_hex(va_list *args, int *count, t_spec spec, const char *hex)
{
	char			*str;
	unsigned int	val;

	val = va_arg(*args, unsigned int);
	str = to_hex_string(val, spec, hex);
	format_print(spec, str, count);
	free(str);
}
