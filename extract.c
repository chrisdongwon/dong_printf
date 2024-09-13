/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:53:25 by cwon              #+#    #+#             */
/*   Updated: 2024/09/12 23:41:16 by cwon             ###   ########.fr       */
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

void	extract_flags(const char **str, t_spec *spec)
{
	if (**str == '#')
	{
		spec->pound = 1;
		(*str)++;
	}
}

void	extract_type(const char **str, t_spec *spec)
{
	if (is_member(**str, "cspdiuxX%"))
	{
		spec->type = **str;
		(*str)++;
	}
}
