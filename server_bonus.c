/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:25:55 by seungryk          #+#    #+#             */
/*   Updated: 2024/03/28 13:06:25 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	print_pid(pid_t	pid)
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	handler(int signum, siginfo_t *info, void *s)
{
	static char	c;
	static int	bit;

	(void)s;
	if (signum == SIGUSR2)
		c = c | (0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		else
			ft_putchar_fd(c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	if (sigemptyset(&act.sa_mask) == -1)
		exit (1);
	if (sigaddset(&act.sa_mask, SIGUSR1) == -1)
		exit (1);
	if (sigaddset(&act.sa_mask, SIGUSR2) == -1)
		exit (1);
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	print_pid(getpid());
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		exit(1);
	while (1)
		sleep(1);
	return (0);
}
