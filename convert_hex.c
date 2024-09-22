/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:21:21 by cwon              #+#    #+#             */
/*   Updated: 2024/09/22 09:33:28 by cwon             ###   ########.fr       */
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
		result[len] = '0';
	else if (spec.pound)
	{
		if (hex[10] == 'a')
			result[1] = 'x';
		else
			result[1] = 'X';
		result[0] = '0';
	}
	while (n)
	{
		result[len--] = hex[n % 16];
		n /= 16;
	}
	return (result);
}

void	convert_hex(va_list *args, int *count, t_spec spec, const char *hex)
{
	char			*str;
	size_t			len;

	str = to_hex_string(va_arg(*args, unsigned int), spec, hex);
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
