/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:53:25 by cwon              #+#    #+#             */
/*   Updated: 2024/09/19 11:44:46 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	extract_flags(const char **str, t_spec *spec)
{
	while (!ft_ismember(**str, "cspdiuxX%.123456789"))
	{
		if (**str == '-')
			spec->minus = 1;
		else if (**str == '0')
			spec->zero = 1;
		else if (**str == '#')
			spec->pound = 1;
		else if (**str == ' ')
			spec->space = 1;
		else if (**str == '+')
			spec->plus = 1;
		(*str)++;
	}
}

static void	extract_width(const char **str, t_spec *spec)
{
	while (str && *str && ft_isdigit(**str))
	{
		spec->width = (spec->width * 10) + (**str - '0');
		(*str)++;
	}
}

static void	extract_precision(const char **str, t_spec *spec)
{
	if (str && *str && **str == '.')
	{
		spec->dot = 1;
		(*str)++;
		while (str && *str && ft_isdigit(**str))
		{
			spec->precision = (spec->precision * 10) + (**str - '0');
			(*str)++;
		}
	}
}

static void	extract_type(const char **str, t_spec *spec)
{
	if (ft_ismember(**str, "cspdiuxX%"))
	{
		spec->type = **str;
		(*str)++;
	}
}

void	extract(const char **str, t_spec *spec)
{
	extract_flags(str, spec);
	extract_width(str, spec);
	extract_precision(str, spec);
	extract_type(str, spec);
}
