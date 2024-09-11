/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:21:21 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 00:18:40 by cwon             ###   ########.fr       */
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
#include <stdio.h>

void	convert_hex(va_list *args, int *count, const char *hex)
{
	unsigned int	n;
	size_t			len;
	char			*str;

	n = va_arg(*args, unsigned int);
	len = hex_length(n);
	str = (char *)malloc(len + 1);
	str[len--] = 0;
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[len--] = hex[n % 16];
		n /= 16;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
