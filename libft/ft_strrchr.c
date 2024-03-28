/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:12:16 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:00:27 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	*str;

	idx = 0;
	str = (char *)s;
	while (str[idx])
		idx++;
	if ((char)c == '\0')
		return (&str[idx]);
	while (idx)
	{
		if (s[idx - 1] == (char)c)
			return (&str[idx - 1]);
		idx--;
	}
	return (0);
}
