/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:45:17 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 00:54:25 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_len(unsigned int n)
{
	size_t	result;

	result = 0;
	if (!n)
		return (1);
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

static char	*ft_utoa(unsigned int n)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = digit_len(n);
	result = (char *)malloc(len + 1);
	if (result)
	{
		result[len] = 0;
		if (!n)
			result[0] = '0';
		i = len - 1;
		while (n)
		{
			result[i--] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (result);
}

void	convert_int(va_list *args, int *count, t_spec spec)
{
	char	*str;
	int		val;

	val = va_arg(*args, int);
	str = ft_itoa(val);
	if (val >= 0 && (spec.plus || spec.space))
	{
		if (spec.plus)
			ft_putchar_fd('+', 1);
		else if (spec.space)
			ft_putchar_fd(' ', 1);
		(*count)++;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	convert_unsigned(va_list *args, int *count)
{
	char	*str;

	str = ft_utoa(va_arg(*args, int));
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
