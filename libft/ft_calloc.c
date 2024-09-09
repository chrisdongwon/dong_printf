/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 06:31:11 by cwon              #+#    #+#             */
/*   Updated: 2024/09/07 19:11:04 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	if ((size_t)(-1) / nmemb < size)
		return (0);
	len = nmemb * size;
	ptr = malloc(len);
	if (ptr)
		ft_bzero(ptr, len);
	return (ptr);
}
