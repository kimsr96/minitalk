/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:25:57 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/28 13:06:45 by seungryk         ###   ########.fr       */
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

void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr_fd("Success sending\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
		ft_error("ARG ");
	signal(SIGUSR1, handler);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid);
	while (1)
		sleep(1);
	return (0);
}
