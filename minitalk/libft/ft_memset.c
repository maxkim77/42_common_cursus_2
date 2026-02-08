/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:26 by jeongkim          #+#    #+#             */
/*   Updated: 2025/04/13 12:05:22 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_mem;

	tmp_mem = (unsigned char *)b;
	while (len > 0)
	{
		*(tmp_mem++) = (unsigned char)c;
		len--;
	}
	return (b);
}
