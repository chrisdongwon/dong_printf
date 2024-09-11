/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:05:50 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 00:23:43 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

// cspdiuxX%

int		ft_printf(const char *format, ...);
void	convert(char *spec, va_list *args, int *count);
void	convert_char(va_list *args, int *count);
void	convert_string(va_list *args, int *count);
// pointer
void	convert_int(va_list *args, int *count);
void	convert_unsigned(va_list *args, int *count);
void	convert_hex(va_list *args, int *count, const char *hex);
void	convert_percent_literal(int *count);

#endif