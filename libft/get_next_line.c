/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:33:38 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/06 13:05:56 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_gnljoin(char *s1, char *s2, int i, int j)
{
	int		idx;
	char	*ret;

	idx = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	ret = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ret)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++idx])
		ret[idx] = s1[idx];
	j = -1;
	while (s2[++j])
		ret[idx + j] = s2[j];
	ret[idx + j] = '\0';
	free(s1);
	return (ret);
}

static	t_gnl	*gnl_lstadd_back(t_gnl **head, int fd)
{
	t_gnl	*new;
	t_gnl	*curr;

	if (!head)
		return (NULL);
	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->save = NULL;
	new->fd = fd;
	new->n = 1;
	new->ret = NULL;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return (*head);
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return (curr->next);
}

t_gnl	*find_list(t_gnl **head, int fd)
{
	t_gnl	*find;

	find = *head;
	if (!(*head))
		return (gnl_lstadd_back(head, fd));
	while (find)
	{
		if (find->fd == fd)
			return (find);
		find = find->next;
	}
	find = gnl_lstadd_back(head, fd);
	return (find);
}

t_gnl	*save_line(int fd, t_gnl **head, t_gnl *g_list)
{
	if (!g_list)
		return (NULL);
	while (check_nl(g_list) && g_list->n != 0)
	{
		g_list->n = read(fd, g_list->buf, BUFFER_SIZE);
		if (g_list->n < 0 || BUFFER_SIZE < 0)
			return (free_all(head, g_list));
		if (!g_list->save)
			g_list->save = ft_gnldup("", 0);
		g_list->buf[g_list->n] = '\0';
		g_list->save = ft_gnljoin(g_list->save, g_list->buf, 0, 0);
		if (!g_list->save)
			return (free_all(head, g_list));
	}
	return (g_list);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*g_list;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	g_list = save_line(fd, &head, find_list(&head, fd));
	if (!g_list)
		return (NULL);
	g_list->ret = ft_gnldup(g_list->save, 1);
	str = ft_backup(g_list->save, g_list->ret);
	if (!str)
	{
		g_list = free_all(&head, g_list);
		return (NULL);
	}
	free(g_list->save);
	g_list->save = str;
	if (g_list->ret)
		return (g_list->ret);
	return (NULL);
}
