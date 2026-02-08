/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:54:27 by jeongkim          #+#    #+#             */
/*   Updated: 2025/04/13 15:05:59 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	c_src = (unsigned char *)src;
	c_dst = (unsigned char *)dst;
	if (c_dst > c_src)
	{
		while (n-- > 0)
			c_dst[n] = c_src[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
