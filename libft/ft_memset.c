/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:23:37 by seungryk          #+#    #+#             */
/*   Updated: 2024/01/23 15:22:10 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	i = 0;
	b_copy = (unsigned char *)b;
	while (i < len)
	{
		b_copy[i] = (unsigned char)c;
		i++;
	}
	return (b_copy);
}
