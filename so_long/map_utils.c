/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 23:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_no_nl(char *dst, char *src, size_t *i, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		if (src[j] != '\n')
			dst[(*i)++] = src[j];
		j++;
	}
}

char	*ft_append_map(char *prev_line, char *new_line,
			size_t len1, size_t len2)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
	{
		ft_free_string(&prev_line);
		return (0);
	}
	i = 0;
	copy_no_nl(str, prev_line, &i, len1);
	copy_no_nl(str, new_line, &i, len2);
	str[i] = '\0';
	ft_free_string(&prev_line);
	return (str);
}

void	check_player_index(t_game *game, char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			game->locate = (int)i;
		i++;
	}
}
