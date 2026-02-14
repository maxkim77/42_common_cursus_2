/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:43:41 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/14 23:47:44 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		width;
	int		height;

	img.player = mlx_xpm_file_to_image(mlx,
			"./textures/player.xpm", &width, &height);
	img.exit = mlx_xpm_file_to_image(mlx,
			"./textures/exit.xpm", &width, &height);
	img.flower = mlx_xpm_file_to_image(mlx,
			"./textures/flower.xpm", &width, &height);
	img.land = mlx_xpm_file_to_image(mlx,
			"./textures/land.xpm", &width, &height);
	img.wall = mlx_xpm_file_to_image(mlx,
			"./textures/wall.xpm", &width, &height);
	if (!img.player || !img.exit || !img.flower || !img.land || !img.wall)
		error("Invalid img\n");
	return (img);
}

void	setting_img(t_game *game, int flag)
{
	size_t	hei;
	size_t	wid;

	hei = 0;
	while (hei < game->height)
	{
		wid = 0;
		while (wid < game->width)
		{
			put_img_to_map(game, (int)wid, (int)hei, flag);
			wid++;
		}
		hei++;
	}
}

void	put_img_to_map(t_game *game, int w, int h, int flag)
{
	if (game->line[h * game->width + w] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.land, w * 64, h * 64);
		if (flag == 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit, w * 64, h * 64);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, w * 64, h * 64);
		game->locate = h * game->width + w;
	}
	else if (game->line[h * game->width + w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.flower, w * 64, h * 64);
	else if (game->line[h * game->width + w] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, w * 64, h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.land, w * 64, h * 64);
}
