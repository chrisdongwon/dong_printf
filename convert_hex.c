/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:21:21 by cwon              #+#    #+#             */
/*   Updated: 2024/09/13 07:39:20 by cwon             ###   ########.fr       */
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

static char	*to_hex_string(unsigned int n, const char *hex)
{
	size_t	len;
	char	*result;

	len = hex_length(n);
	result = (char *)malloc(len + 1);
	result[len--] = 0;
	if (!n)
		result[0] = '0';
	while (n)
	{
		result[len--] = hex[n % 16];
		n /= 16;
	}
	return (result);
}

void	convert_hex(va_list *args, int *count, int pound, const char *hex)
{
	char	*str;

	str = to_hex_string(va_arg(*args, unsigned int), hex);
	if (pound)
	{
		if (hex[10] == 'a')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
		*count += 2;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
