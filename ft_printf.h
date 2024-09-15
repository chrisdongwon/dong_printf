/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:05:50 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 14:37:40 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_spec
{
	int		minus;
	int		zero;
	int		dot;
	int		pound;
	int		space;
	int		plus;
	size_t	width;
	size_t	precision;
	char	type;
}	t_spec;

int		ft_printf(const char *format, ...);

void	extract(const char **str, t_spec *spec);

void	convert(t_spec spec, va_list *args, int *count);
void	pad(t_spec, int *count, size_t len, char c);
void	format_print(t_spec spec, char *str, int *count);

void	convert_char(va_list *args, int *count, t_spec spec);
void	convert_string(va_list *args, int *count, t_spec spec);
void	convert_pointer(va_list *args, int *count, t_spec spec);
void	convert_int(va_list *args, int *count, t_spec spec);
void	convert_unsigned(va_list *args, int *count, t_spec spec);
void	convert_hex(va_list *args, int *count, t_spec spec, const char *hex);
void	convert_percent_literal(int *count);

#endif