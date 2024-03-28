/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:49:52 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/13 17:33:38 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	idx;
	char	*ptr;

	idx = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (idx < size * count)
	{
		ptr[idx] = 0;
		idx++;
	}
	return (ptr);
}
