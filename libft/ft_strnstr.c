/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:23:41 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:10:12 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	find;

	idx = 0;
	if (len == 0 && (!haystack || !needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[idx] && idx < len)
	{
		find = 0;
		while (idx + find < len && haystack[idx + find] && \
				haystack[idx + find] == needle[find])
			find++;
		if (needle[find] == '\0')
			return ((char *)&haystack[idx]);
		idx++;
	}
	return (0);
}
