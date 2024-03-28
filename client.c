/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:25:57 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/28 12:37:31 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	send_char(char c, int pid)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		if (c & (0x80 >> shift))
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("PID ");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("PID ");
		}
		shift++;
		usleep(100);
	}
}

void	send_signals(char *message, int pid)
{
	int	i;

	i = 0;
	if (message[0] != '\0')
	{
		while (message[i])
		{
			send_char(message[i], pid);
			i++;
		}
		send_char('\n', pid);
	}
	send_char('\0', pid);
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
		ft_error("ARG ");
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}
