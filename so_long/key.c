/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:49 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:43:50 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_index(t_game *game, int i)
{
	if (!game || !game->line)
		return (0);
	if (i < 0)
		return (0);
	if (game->line[i] == '\0')
		return (0);
	return (1);
}

int	key_press(int keycode, t_game *game)
{
	int	next;

	if (!game)
		return (0);
	if (keycode == KEY_ESC)
		return (exit_game(game), 0);
	next = game->locate;
	if (keycode == KEY_W)
		next = game->locate - (int)game->width;
	else if (keycode == KEY_S)
		next = game->locate + (int)game->width;
	else if (keycode == KEY_A)
		next = game->locate - 1;
	else if (keycode == KEY_D)
		next = game->locate + 1;
	else
		return (0);
	if (!is_valid_index(game, next))
		return (0);
	move_player(game, next);
	return (0);
}
