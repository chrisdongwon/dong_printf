/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:05:50 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 23:38:41 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_spec
{
	char				*flags;
	unsigned long long	width;
	unsigned long long	precision;
	char				type;
	int					pound;
	int					space;
	int					plus;
	int					minus;
	int					zero;
	int					dot;
}	t_spec;

int		ft_printf(const char *format, ...);
void	convert(t_spec spec, va_list *args, int *count);
void	convert_char(va_list *args, int *count);
void	convert_string(va_list *args, int *count);
void	convert_pointer(va_list *args, int *count);
void	convert_int(va_list *args, int *count);
void	convert_unsigned(va_list *args, int *count);
void	convert_hex(va_list *args, int *count, int pound, const char *hex);
void	convert_percent_literal(int *count);
void	extract_flags(const char **str, t_spec *spec);
void	extract_type(const char **str, t_spec *spec);

#endif