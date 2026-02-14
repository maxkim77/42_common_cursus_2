/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 22:44:47 by jeongkim          #+#    #+#             */
/*   Updated: 2026/02/15 00:34:16 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"

# define EVENT_KEY_PRESS 2
# define EVENT_DESTROY 17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/*
** macOS (minilibx_opengl)
**
** # include "minilibx-linux/minilibx_macos_opengl.h"
** # define KEY_ESC 53
** # define KEY_W 13
** # define KEY_A 0
** # define KEY_S 1
** # define KEY_D 2
*/

typedef struct s_img
{
	void	*player;
	void	*exit;
	void	*flower;
	void	*land;
	void	*wall;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	size_t	width;
	size_t	height;
	int		cnt_p;
	int		cnt_e;
	int		cnt_c;
	int		current_c;
	char	*line;
	t_img	img;
	int		locate;
	int		walk_cnt;
	int		path_valid;
	int		path_check_c;
}	t_game;

void	game_init(t_game *game, char *map);

void	setting_map(t_game *game, char *map);
void	map_check_empty_line(char *line);
void	map_read_first_line(t_game *game, int fd);
void	map_append_or_error(t_game *game, char *line);

char	*ft_append_map(char *prev_line, char *new_line,
			size_t len1, size_t len2);
void	check_player_index(t_game *game, char *line);

void	map_check(t_game *game);
void	is_rectangular(t_game *game);
void	is_valid_map_wall(t_game *game);
void	is_valid_map_params(t_game *game);

void	path_check(t_game *game);
void	dfs(t_game *game, int location, char *map);
int		check_move(int i, t_game *game);

t_img	img_init(void *mlx);
void	setting_img(t_game *game, int flag);
void	put_img_to_map(t_game *game, int w, int h, int flag);

int		key_press(int keycode, t_game *game);
void	move_player(t_game *game, int i);
void	player_loaction_init(t_game *game, int i, int flag);
int		print_walk_cnt(t_game *game);
int		exit_game(t_game *game);

void	error(char *s);
void	ft_free_string(char **s);

#endif
