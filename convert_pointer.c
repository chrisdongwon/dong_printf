/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:04:28 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 10:17:43 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_length(unsigned long n)
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

static char	*to_hex_string(unsigned long n, const char *hex)
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

void	convert_pointer(va_list *args, int *count)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*args, void *);
	if (!ptr)
		str = ft_strdup("(nil)");
	else
	{
		str = to_hex_string((unsigned long)ptr, "0123456789abcdef");
		ft_putstr_fd("0x", 1);
		*count += 2;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
