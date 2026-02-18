/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/18 19:20:17 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	client_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		send_char(server_pid, (unsigned char)str[i++]);
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	struct sigaction	s_client;
	int					server_pid;

	if (ac != 3)
	{
		ft_putstr_fd("format: ./client <server PID> <string>\n", 1);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0) < 0)
	{
		ft_putstr_fd("error: invalid PID\n", 1);
		return (EXIT_FAILURE);
	}
	g_ack = 0;
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	client_send_message(server_pid, av[2]);
	return (EXIT_SUCCESS);
}
