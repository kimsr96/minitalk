/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:55:34 by seungryk          #+#    #+#             */
/*   Updated: 2023/10/17 14:37:35 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	long long	temp;
	int			idx;
	int			sign;

	num = 0;
	idx = 0;
	sign = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	while (str[idx] && (str[idx] >= '0' && str[idx] <= '9'))
	{
		temp = num * 10 + (str[idx] - '0');
		if (temp < num)
			return (-1 + (sign < 0));
		num = temp;
		idx++;
	}
	return (num * sign);
}
