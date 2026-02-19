/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:56 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/19 11:12:51 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("argc != 2\n");
	if (ft_strrchr(argv[1], '.') == 0
		|| ft_memcmp(ft_strrchr(argv[1], '.'), ".ber\0", 5) != 0)
		error("This file is not .ber file.\n");
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	game_init(game, argv[1]);
	mlx_hook(game->win, EVENT_KEY_PRESS, 1L << 0, key_press, game);
	mlx_hook(game->win, EVENT_DESTROY, 0, exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
