/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:21:31 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 13:37:01 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cnt;

	cnt = 0;
	if (!lst)
		return (cnt);
	while (lst)
	{
		cnt += 1;
		lst = lst->next;
	}
	return (cnt);
}
