/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/15 00:29:39 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map_body(t_game *game, int fd)
{
	char	*line;

	game->height = 0;
	if (game->line && ft_memcmp(game->line, "\n", 1) != 0)
		game->height++;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_check_empty_line(line);
		if (ft_memcmp(line, "\n", 1) != 0)
			game->height++;
		map_append_or_error(game, line);
		ft_free_string(&line);
	}
}

void	setting_map(t_game *game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error("File Error\n");
	map_read_first_line(game, fd);
	read_map_body(game, fd);
	close(fd);
	check_player_index(game, game->line);
}
