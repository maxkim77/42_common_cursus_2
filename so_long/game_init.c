/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 23:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char *map)
{
	game->cnt_p = 0;
	game->cnt_e = 0;
	game->cnt_c = 0;
	game->current_c = 0;
	game->height = 0;
	game->walk_cnt = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx_init failed\n");
	game->img = img_init(game->mlx);
	setting_map(game, map);
	map_check(game);
	path_check(game);
	game->win = mlx_new_window(game->mlx, (int)(game->width * 64),
			(int)(game->height * 64), "so_long");
	if (!game->win)
		error("mlx_new_window failed\n");
	setting_img(game, 0);
}
