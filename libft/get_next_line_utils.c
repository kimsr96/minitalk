/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:25:12 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/06 13:04:02 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*last_node(t_gnl **head, t_gnl *g_list)
{
	t_gnl	*curr;

	curr = *head;
	while (curr)
	{
		if (curr->next == g_list || curr->next == NULL)
			break ;
		curr = curr->next;
	}
	return (curr);
}

void	*free_all(t_gnl **head, t_gnl *g_list)
{
	t_gnl	*curr;

	if (*head == NULL || g_list == NULL)
		return (NULL);
	if (*head != g_list)
	{
		curr = last_node(head, g_list);
		if (curr->next != NULL)
			curr->next = g_list->next;
	}
	else
		*head = g_list->next;
	if (g_list->save && g_list->ret && g_list->n >= 0)
	{
		free(g_list->ret);
		g_list->ret = NULL;
	}
	if (g_list->save)
	{
		free(g_list->save);
		g_list->save = NULL;
	}
	free(g_list);
	g_list = NULL;
	return (NULL);
}

ssize_t	check_nl(t_gnl *gnl_list)
{
	ssize_t	i;

	i = 0;
	if (!gnl_list->save)
		return (1);
	while (gnl_list->save[i])
	{
		if (gnl_list->save[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_backup(char *save, char *ret)
{
	int		s_len;
	int		r_len;
	char	*dest;

	if (!save || !ret)
		return (NULL);
	s_len = 0;
	r_len = 0;
	while (save[s_len])
		s_len++;
	while (ret[r_len] != '\n' && ret[r_len] != '\0')
		r_len++;
	if (ret[r_len] == '\n')
		r_len++;
	dest = ft_gnldup(&save[r_len], 0);
	if (!dest)
		return (NULL);
	return (dest);
}

char	*ft_gnldup(const char *s1, int flag)
{
	int		idx;
	int		s_len;
	char	*dest;

	idx = -1;
	s_len = 0;
	if (flag == 1)
	{
		while (s1[s_len] != '\n' && s1[s_len] != '\0')
			s_len++;
		if (s1[s_len] == '\n')
			s_len++;
	}
	else
		while (s1[s_len] != '\0')
				s_len++;
	if (s_len == 0 && flag != 0)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dest)
		return (NULL);
	while (s1[++idx] && idx < s_len)
		dest[idx] = s1[idx];
	dest[idx] = '\0';
	return (dest);
}
