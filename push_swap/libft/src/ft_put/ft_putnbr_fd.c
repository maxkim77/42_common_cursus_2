/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:52:09 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 23:52:09 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static	void	putnbr_fd(long int nb, int fd)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb > 9)
	{
		putnbr_fd(nb / 10, fd);
		putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	putnbr_fd(nb, fd);
}
