/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 23:50:57 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/21 23:50:58 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (num > 0)
	{
		*p = (unsigned char)value;
		p++;
		num--;
	}
	return (ptr);
}
