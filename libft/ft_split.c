/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:53:48 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:35:37 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freeall(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		cnt;

	j = 0;
	cnt = 0;
	while (s[j] && s[j] == c)
		j++;
	i = j;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i] == '\0')
				break ;
			cnt += 1;
		}
		else
			i++;
	}
	if (i == 0 || i == j)
		return (cnt);
	return (cnt + 1);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*put_word(char const *s, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	char	**ret;

	i = -1;
	idx = 0;
	if (!s)
		return (NULL);
	ret = (char **)ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c)
		{
			ret[idx] = put_word(&s[i], word_len(&s[i], c));
			if (!ret[idx++])
				return (ft_freeall(ret));
			i += (word_len(&s[i], c) - 1);
		}
	}
	ret[idx] = NULL;
	return (ret);
}
