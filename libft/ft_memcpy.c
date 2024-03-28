/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:58:24 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:02:16 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		idx;
	char		*dst_copy;
	const char	*src_copy;

	idx = 0;
	if (dst == 0 && src == 0)
		return (0);
	dst_copy = dst;
	src_copy = src;
	while (idx < n)
	{
		dst_copy[idx] = src_copy[idx];
		idx++;
	}
	return (dst_copy);
}
