/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:53:25 by cwon              #+#    #+#             */
/*   Updated: 2024/09/15 00:33:16 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_member(const char c, const char *arr)
{
	while (arr && *arr)
	{
		if (*(arr++) == c)
			return (1);
	}
	return (0);
}

static void	extract_flags(const char **str, t_spec *spec)
{
	while (!is_member(**str, "cspdiuxX%.") && !ft_isdigit(**str))
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
	while (str && *str && **str && ft_isdigit(**str))
	{
		spec->width = (spec->width * 10) + (**str - '0');
		(*str)++;
	}
}

void	extract(const char **str, t_spec *spec)
{
	extract_flags(str, spec);
	extract_width(str, spec);
	// extract precision
	if (is_member(**str, "cspdiuxX%"))
	{
		spec->type = **str;
		(*str)++;
	}
}
