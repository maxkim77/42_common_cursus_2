/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 23:30:00 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 22:29:25 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_collect(t_game *game, int i)
{
	game->current_c++;
	player_loaction_init(game, i, 0);
}

static void	handle_exit(t_game *game, int i)
{
	if (game->cnt_c == game->current_c)
	{
		game->walk_cnt++;
		ft_printf("Total walk count : %d\n", game->walk_cnt);
		exit(0);
	}
	player_loaction_init(game, i, 1);
	game->line[i] = 'E';
}

void	move_player(t_game *game, int i)
{
	if (!game || !game->line)
		return ;
	if (game->line[i] == '1')
		return ;
	if (game->line[i] == '0')
		player_loaction_init(game, i, 0);
	else if (game->line[i] == 'C')
		handle_collect(game, i);
	else if (game->line[i] == 'E')
		handle_exit(game, i);
	print_walk_cnt(game);
}

void	player_loaction_init(t_game *game, int i, int flag)
{
	if (!game || !game->line)
		return ;
	game->line[i] = 'P';
	if (game->line[game->locate] != 'E')
		game->line[game->locate] = '0';
	game->locate = i;
	setting_img(game, flag);
}

int	print_walk_cnt(t_game *game)
{
	if (!game)
		return (0);
	game->walk_cnt++;
	ft_printf("%d\n", game->walk_cnt);
	return (game->walk_cnt);
}
