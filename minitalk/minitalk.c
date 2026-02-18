/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:49:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/18 19:49:12 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		exit(EXIT_FAILURE);
}

static int	get_sig_from_bit(char bit)
{
	if (bit == 0)
		return (SIGUSR1);
	return (SIGUSR2);
}

void	send_bit(pid_t pid, char bit, char pause_yn)
{
	int	sig;

	(void)pause_yn;
	sig = get_sig_from_bit(bit);
	g_ack = 0;
	if (kill(pid, sig) < 0)
		exit(EXIT_FAILURE);
	while (g_ack == 0)
		usleep(50);
}

void	send_char(pid_t pid, char c)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (char)((c >> i) & 1);
		send_bit(pid, bit, 0);
		i--;
	}
}
