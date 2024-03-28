/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:53:57 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:25 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s;
	while (*s_copy)
	{
		if (*s_copy == (char)c)
			return (s_copy);
		s_copy++;
	}
	if ((char)c == '\0')
		return (s_copy);
	else
		return (0);
}
