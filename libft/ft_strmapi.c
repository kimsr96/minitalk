/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:28:20 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:29:54 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*ret;

	idx = 0;
	if (!s || !f)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == 0)
		return (NULL);
	while (s[idx])
	{
		ret[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
