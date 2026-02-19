/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:20:32 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/19 14:55:24 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*read_from_file(char *remain_line, int fd)
{
	ssize_t	bytes_read;
	char	*temp_line;

	temp_line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp_line)
		return (ft_free(remain_line), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(remain_line, '\n'))
	{
		bytes_read = read(fd, temp_line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(temp_line);
			ft_free(remain_line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		temp_line[bytes_read] = '\0';
		remain_line = ft_strjoin(remain_line, temp_line);
		if (!remain_line)
			return (ft_free(temp_line), NULL);
	}
	free(temp_line);
	return (remain_line);
}

char	*ft_free(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (NULL);
}

char	*extract_line(char *remain_line)
{
	char	*line;
	int		len;

	len = 0;
	if (!remain_line[len])
		return (NULL);
	while (remain_line[len] && remain_line[len] != '\n')
		len++;
	if (remain_line[len] == '\n')
		line = ft_calloc(len + 2, sizeof(char));
	else
		line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (free(remain_line), NULL);
	len = -1;
	while (remain_line[++len] && remain_line[len] != '\n')
		line[len] = remain_line[len];
	if (remain_line[len] == '\n')
	{
		line[len] = remain_line[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*get_remain_line(char *remain_line)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while ((remain_line)[i] && (remain_line)[i] != '\n')
		i++;
	if ((remain_line)[i] == '\n')
		i++;
	if (!(remain_line)[i])
		return (ft_free(remain_line), NULL);
	line = ft_calloc(ft_strlen((remain_line) + i) + 1, sizeof(char));
	if (!line)
		return (ft_free(remain_line), NULL);
	while ((remain_line)[i])
		line[j++] = (remain_line)[i++];
	line[j] = '\0';
	free(remain_line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	remain_line = read_from_file(remain_line, fd);
	if (!remain_line)
	{
		return (NULL);
	}
	line = extract_line(remain_line);
	if (!line)
	{
		remain_line = NULL;
		return (NULL);
	}
	remain_line = get_remain_line(remain_line);
	return (line);
}
