/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/04/13 15:06:32 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*conversion;
	int		count;
	long	nbr;

	nbr = n;
	count = ft_count(nbr);
	conversion = malloc(sizeof(char) * (count + 1));
	if (!conversion)
		return (NULL);
	conversion[count] = '\0';
	if (nbr == 0)
		conversion[0] = '0';
	if (nbr < 0)
	{
		conversion[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		conversion[--count] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (conversion);
}
