/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:02:14 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 13:35:32 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len >= start + len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else if (s_len < start)
		str = (char *)malloc(sizeof(char) * 1);
	else
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (str == 0)
		return (0);
	while (start < s_len && s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
