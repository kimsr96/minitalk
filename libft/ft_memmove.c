/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:37:45 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 13:43:08 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		idx;
	char		*dst_copy;
	const char	*src_copy;

	idx = -1;
	dst_copy = dst;
	src_copy = src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst <= src)
	{
		while (++idx < len)
			dst_copy[idx] = src_copy[idx];
	}
	else
	{
		while (len)
		{
			dst_copy[len - 1] = src_copy[len - 1];
			len --;
		}
	}
	return (dst);
}
