/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:30:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:29:39 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	if (game && game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
