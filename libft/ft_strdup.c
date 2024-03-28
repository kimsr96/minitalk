/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:20:10 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 13:58:14 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s_len;
	int		idx;
	char	*dest;

	s_len = 0;
	idx = 0;
	while (s1[s_len])
		s_len++;
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (NULL);
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
