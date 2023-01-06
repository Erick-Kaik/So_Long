/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:15:40 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 20:37:36 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "Libft/libft.h"
# include <stddef.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# ifndef PIXEL_MAP
#  define PIXEL_MAP 48
# endif

typedef struct s_layout
{
	char	**map;
	int		row;
	int		column;
	int		player[3];
	size_t	collect;
	int		goal;
}	t_layout;

typedef struct s_image
{
	void	*player;
	void	*floor;
	void	*wup;
	void	*wlf;
	void	*wrg;
	void	*wdw;
	void	*wul;
	void	*wur;
	void	*wdl;
	void	*wdr;
	void	*wmid;
	void	*key;
	void	*exit;
	int		create;
}	t_image;

typedef struct s_trap
{
	void	*trap;
	void	*t_trap;
	size_t	check;
	size_t	t_check;
	size_t	player_trap;
	size_t	count;
	size_t	t_count;
}	t_trap;

typedef struct s_game
{
	void		*link;
	void		*win;
	t_layout	layout;
	t_image		img;
	t_trap		trap;
	size_t		moves;
	size_t		score;
	size_t		open;
	char		*n_moves;
}	t_game;

int		ft_init(t_game *game);
int		ft_render(t_game *game);
void	ft_select_image(t_game *game, char char_map, int x, int y);
void	ft_create_images(t_game *game);
void	ft_check(char *filename, t_game *game);
int		ft_check_ber(const char *str, char *find, t_game *game);
int		ft_clear_window(char *str, t_game *game);
void	ft_close(char *str, int validate, t_game *game);
void	ft_load_struct(t_game *game);
int		ft_look_layout(char *line, t_game *game);
void	ft_fill_map(char *filename, t_game *game);
void	ft_verify_border(t_game *game);
int		ft_verify_up_down(t_game *game);
int		ft_verify_right_left(t_game *game);
int		ft_key_press(int key, t_game *game);
void	ft_move(int key, t_game *game);
void	ft_up_move(t_game *game);
void	ft_left_move(t_game *game);
void	ft_down_move(t_game *game);
void	ft_right_move(t_game *game);
void	ft_validate_move(int row, int col, t_game *game);
void	ft_change_map(int Nrow, int Ncol, char flag, t_game *game);
void	ft_wall(int size, t_game *game);
void	ft_put_wall(int x, int y, t_game *game);
void	ft_open_door(t_game *game, int anim, int l);
void	ft_anim_player(t_game *game, int anim, int l);
void	ft_check_trap(t_game *game, int l, char flag);
void	ft_trap(t_game *game, int anim, int l);
char	*ft_get_xpm_file(char *file, int count);
void	ft_player_death(t_game *game, int anim, int l);
void	ft_player_trap(int Nrow, int Ncol, char flag, t_game *game);
void	ft_anim_player_trap(t_game *game, int anim, int l);
int		ft_press_x(t_game *game);
void	ft_check_map(t_game *game, int x);
void	ft_validate_ber(int *map_open, char *filename, t_game *game);

#endif 