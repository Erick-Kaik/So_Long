/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:21:05 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/08 16:22:11 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_render(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	game->n_moves = ft_itoa(game->moves);
	if (game->img.create == 0)
		ft_create_images(game);
	else if (game->score == game->layout.collect && game->open == 0)
		ft_open_door(game, 14, 48);
	while (game->layout.map[x] != NULL)
	{
		y = 0;
		while (game->layout.map[x][y] != '\0')
		{
			ft_select_image(game, game->layout.map[x][y], x, y);
			y++;
		}
		x++;
	}
	mlx_string_put(game->link, game->win, 7, 21, 0x000000, game->n_moves);
	free(game->n_moves);
	return (0);
}

void	ft_select_image(t_game *game, char char_map, int x, int y)
{
	x = x * PIXEL_MAP;
	y = y * PIXEL_MAP;
	if (char_map == '1')
		ft_put_wall(x, y, game);
	else if (char_map == '0')
		mlx_put_image_to_window(game->link, game->win, game->img.floor, y, x);
	else if (char_map == 'C')
		mlx_put_image_to_window(game->link, game->win, game->img.key, y, x);
	else if (char_map == 'E')
		mlx_put_image_to_window(game->link, game->win, game->img.exit, y, x);
	else if (char_map == 'P')
	{
		ft_anim_player(game, 5, 48);
		mlx_put_image_to_window(game->link, game->win, game->img.player, y, x);
	}
	else if (char_map == 'T' || char_map == 't')
	{
		ft_check_trap(game, 48, char_map);
		if (char_map == 'T')
			mlx_put_image_to_window(game->link, game->win,
				game->trap.trap, y, x);
		else
			mlx_put_image_to_window(game->link, game->win,
				game->trap.t_trap, y, x);
	}
}

void	ft_create_images(t_game *game)
{
	int	pixel_map;

	pixel_map = PIXEL_MAP;
	ft_wall(pixel_map, game);
	game->img.floor = mlx_xpm_file_to_image(game->link,
			"sprites/floor/Floor.xpm", &pixel_map, &pixel_map);
	game->img.player = mlx_xpm_file_to_image(game->link,
			"sprites/player/Player0.xpm", &pixel_map, &pixel_map);
	game->img.key = mlx_xpm_file_to_image(game->link,
			"sprites/collect/CollectKey.xpm", &pixel_map, &pixel_map);
	game->img.exit = mlx_xpm_file_to_image(game->link,
			"sprites/exit/DoorLook.xpm", &pixel_map, &pixel_map);
	game->trap.trap = mlx_xpm_file_to_image(game->link,
			"sprites/trap/Trap0.xpm", &pixel_map, &pixel_map);
	game->trap.t_trap = mlx_xpm_file_to_image(game->link,
			"sprites/player/PlayerTrap0.xpm", &pixel_map, &pixel_map);
	game->img.create = 1;
}

void	ft_wall(int size, t_game *game)
{
	game->img.wdw = mlx_xpm_file_to_image(game->link,
			"sprites/wall/Down_Wall0.xpm", &size, &size);
	game->img.wdl = mlx_xpm_file_to_image(game->link,
			"sprites/wall/DownLeft_Wall0.xpm", &size, &size);
	game->img.wdr = mlx_xpm_file_to_image(game->link,
			"sprites/wall/DownRight_Wall0.xpm", &size, &size);
	game->img.wlf = mlx_xpm_file_to_image(game->link,
			"sprites/wall/Left_Wall0.xpm", &size, &size);
	game->img.wrg = mlx_xpm_file_to_image(game->link,
			"sprites/wall/Right_Wall0.xpm", &size, &size);
	game->img.wup = mlx_xpm_file_to_image(game->link,
			"sprites/wall/Up_Wall0.xpm", &size, &size);
	game->img.wul = mlx_xpm_file_to_image(game->link,
			"sprites/wall/UpLeft_Wall0.xpm", &size, &size);
	game->img.wur = mlx_xpm_file_to_image(game->link,
			"sprites/wall/UpRight_Wall0.xpm", &size, &size);
	game->img.wmid = mlx_xpm_file_to_image(game->link,
			"sprites/wall/WallMid.xpm", &size, &size);
}

void	ft_put_wall(int x, int y, t_game *game)
{
	if (x / 48 == 0 && y / 48 == 0)
		mlx_put_image_to_window(game->link, game->win, game->img.wul, y, x);
	else if (x / 48 == 0 && y / 48 == game->layout.column - 1)
		mlx_put_image_to_window(game->link, game->win, game->img.wur, y, x);
	else if (x / 48 == game->layout.row - 1 && y / 48 == 0)
		mlx_put_image_to_window(game->link, game->win, game->img.wdl, y, x);
	else if (x / 48 == game->layout.row - 1
		&& y / 48 == game->layout.column - 1)
		mlx_put_image_to_window(game->link, game->win, game->img.wdr, y, x);
	else if (x / 48 == 0)
		mlx_put_image_to_window(game->link, game->win, game->img.wup, y, x);
	else if (x / 48 == game->layout.row - 1)
		mlx_put_image_to_window(game->link, game->win, game->img.wdw, y, x);
	else if (y / 48 == 0)
		mlx_put_image_to_window(game->link, game->win, game->img.wlf, y, x);
	else if (y / 48 == game->layout.column - 1)
		mlx_put_image_to_window(game->link, game->win, game->img.wrg, y, x);
	else
		mlx_put_image_to_window(game->link, game->win, game->img.wmid, y, x);
}
