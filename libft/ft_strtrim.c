/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:56:48 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:15:24 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (s1[i] && len && check_set(set, s1[i]))
	{
		len--;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (i && len && check_set(set, s1[i]))
	{
		len--;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	idx;
	char	*ret;

	i = 0;
	idx = 0;
	if (!s1 || !set)
		return (NULL);
	len = get_len(s1, set);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	while (s1[i] && check_set(set, s1[i]))
		i++;
	while (idx < len && s1[i])
	{
		ret[idx] = s1[i];
		i++;
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
