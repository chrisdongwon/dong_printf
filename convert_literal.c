/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_literal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:17:39 by cwon              #+#    #+#             */
/*   Updated: 2024/09/21 17:58:02 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(va_list *args, int *count, t_spec spec)
{
	char	*space_pad;
	size_t	space_len;

	space_len = 0;
	if (spec.width > 1)
		space_len = spec.width - 1;
	space_pad = pad_string(space_len, ' ');
	if (!spec.minus)
	{
		ft_putstr_fd(space_pad, 1);
		*count += space_len;
	}
	ft_putchar_fd(va_arg(*args, int), 1);
	*count += 1;
	if (spec.minus)
	{
		ft_putstr_fd(space_pad, 1);
		*count += space_len;
	}
	free(space_pad);
}

void	convert_string(va_list *args, int *count, t_spec spec)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str)
	{
		if (spec.dot)
			str = ft_substr(str, 0, spec.precision);
		else
			str = ft_strdup(str);
	}
	else
	{
		if (spec.dot && spec.precision < 6)
			str = ft_strdup("");
		else
			str = ft_strdup("(null)");
	}
	format_print(spec, str, count);
}

void	convert_percent_literal(int *count)
{
	ft_putchar_fd('%', 1);
	*count += 1;
}
