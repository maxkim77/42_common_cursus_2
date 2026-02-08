/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:44:52 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/08 22:30:47 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_handler(int sig, siginfo_t *info, void *context)
{
	static t_protocol	s;
	static pid_t		cur_pid;

	(void)context;
	if (cur_pid != info->si_pid)
	{
		cur_pid = info->si_pid;
		s.bits = 0;
		s.data = 0;
	}
	if (sig == SIGUSR2)
		s.data |= (1 << (7 - s.bits));
	s.bits++;
	if (s.bits == 8)
	{
		if (s.data == '\0')
			write(STDOUT_FILENO, "\n", 1);
		else
			write(STDOUT_FILENO, &s.data, 1);
		s.bits = 0;
		s.data = 0;
	}
}

int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	sigaddset(&s_server.sa_mask, SIGUSR1);
	sigaddset(&s_server.sa_mask, SIGUSR2);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&s_server);
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
