/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:20:41 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:20:43 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			bytes;

	i = 0;
	bytes = count * size;
	if (size && ((bytes / size) != count))
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	char_c;

	char_c = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (*s != char_c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	counter_1;
	size_t	counter_2;

	counter_1 = -1;
	counter_2 = 0;
	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (0);
	}
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (free(s1), NULL);
	while (s1[++counter_1] != '\0')
		s3[counter_1] = s1[counter_1];
	while (s2[counter_2] != '\0')
	{
		s3[counter_1 + counter_2] = s2[counter_2];
		counter_2++;
	}
	s3[counter_1 + counter_2] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}