/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:05:50 by cwon              #+#    #+#             */
/*   Updated: 2024/09/22 09:33:23 by cwon             ###   ########.fr       */
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
	int		precision;
	char	type;
}	t_spec;

int		ft_printf(const char *format, ...);

void	extract(const char **str, t_spec *spec, va_list *args);

void	convert(t_spec spec, va_list *args, int *count);
void	format_print(t_spec spec, char *str, int *count);

char	*pad_string(size_t n, const char c);
void	pad_zero(char **str, size_t n);

void	convert_char(va_list *args, int *count, t_spec spec);
void	convert_string(va_list *args, int *count, t_spec spec);
void	convert_int(va_list *args, int *count, t_spec spec);
void	convert_unsigned(va_list *args, int *count, t_spec spec);
void	convert_hex(va_list *args, int *count, t_spec spec, const char *hex);
void	convert_pointer(va_list *args, int *count, t_spec spec);
void	convert_percent_literal(int *count);

#endif