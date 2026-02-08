/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 17:48:13 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/08 17:48:20 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		exit(EXIT_FAILURE);
}

void	send_bit(pid_t pid, char bit, char pause_yn)
{
	int	sig;

	(void)pause_yn;
	if (bit == 0)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) < 0)
		exit(EXIT_FAILURE);
	usleep(WAIT_US);
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
