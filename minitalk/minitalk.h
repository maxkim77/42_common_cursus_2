/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:54:43 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/18 19:19:36 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define WAIT_US 200

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_protocol
{
	int				bits;
	unsigned char	data;
}	t_protocol;

void	configure_sigaction_signals(struct sigaction *sa);
void	send_bit(pid_t pid, char bit, char pause_yn);
void	send_char(pid_t pid, char c);

extern volatile sig_atomic_t	g_ack;

#endif
