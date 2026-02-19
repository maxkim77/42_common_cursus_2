/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:44:28 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/19 23:38:44 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangular(t_game *game)
{
	if (game->width * game->height != ft_strlen(game->line))
		error("Map is not rectangular.\n");
}

void	is_valid_map_wall(t_game *game)
{
	size_t	col;
	size_t	end_index;

	col = 0;
	end_index = ft_strlen(game->line) - 1;
	while (col < end_index)
	{
		if (col < game->width && game->line[col] != '1')
			error("Top wall is not valid\n");
		else if (col == 0 || col % game->width == game->width - 1)
		{
			if (game->line[col] != '1')
				error("Left-Right wall is not valid\n");
		}
		else if (col > end_index - game->width && game->line[col] != '1')
			error("Bottom wall is not valid\n");
		col++;
	}
}

void	is_valid_map_params(t_game *game)
{
	int	i;
	int	end_index;

	i = 0;
	end_index = ft_strlen(game->line) - 1;
	while (i++ < end_index)
	{
		if (game->line[i] == 'E')
			game->cnt_e++;
		else if (game->line[i] == 'P')
			game->cnt_p++;
		else if (game->line[i] == 'C')
			game->cnt_c++;
		else
		{
			if (game->line[i] != '1' && game->line[i] != '0')
				error("Map parmas is not valid!\n");
		}
	}
	if (game->cnt_p != 1 || game->cnt_e != 1 || game->cnt_c <= 0)
		error("Map parmas is not valid!\n");
}

void	map_check(t_game *game)
{
	is_rectangular(game);
	is_valid_map_wall(game);
	is_valid_map_params(game);
}
