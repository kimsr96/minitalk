/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:26:38 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:00:34 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;

	i = 0;
	s_copy = (unsigned char *)s;
	while (i < n)
	{
		if (s_copy[i] == (unsigned char)c)
			return (s_copy + i);
		i++;
	}
	return (0);
}
