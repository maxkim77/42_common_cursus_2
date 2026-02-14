/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:56:26 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_empty_line(char *line)
{
	if (ft_memcmp(line, "\n", 1) == 0)
	{
		ft_free_string(&line);
		error("Empty line in map\n");
	}
}

void	map_read_first_line(t_game *game, int fd)
{
	game->line = get_next_line(fd);
	if (!game->line || ft_strlen(game->line) == 0)
		error("Empty\n");
	game->width = ft_strlen(game->line) - 1;
}

void	map_append_or_error(t_game *game, char *line)
{
	size_t	len;
	size_t	cur_len;

	len = ft_strlen(line);
	if (!(len == game->width || (len > 0 && len - 1 == game->width)))
		error("Map width error\n");
	cur_len = ft_strlen(game->line);
	game->line = ft_append_map(game->line, line, cur_len, len);
}
