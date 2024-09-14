/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_literal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:17:39 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 00:40:20 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(va_list *args, int *count)
{
	ft_putchar_fd(va_arg(*args, int), 1);
	*count += 1;
}

void	convert_string(va_list *args, int *count)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}

void	convert_percent_literal(int *count)
{
	ft_putchar_fd('%', 1);
	*count += 1;
}
