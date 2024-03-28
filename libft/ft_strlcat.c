/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:52:18 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:12:13 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	len_dst;
	size_t	len_src;

	idx = 0;
	len_dst = 0;
	len_src = 0;
	if (dstsize == 0 && (!dst || !src))
		return (0);
	while (dst[len_dst])
		len_dst++;
	while (src[len_src])
		len_src++;
	while (idx + len_dst + 1 < dstsize && src[idx])
	{
		dst[len_dst + idx] = src[idx];
		idx++;
	}
	dst[len_dst + idx] = '\0';
	if (dstsize < len_dst)
		return (len_src + dstsize);
	else
		return (len_src + len_dst);
}
