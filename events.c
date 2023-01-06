/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:36 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/08/12 15:09:20 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_key_press(int key, t_game *game)
{
	if (ft_strchr("wasd", key))
		ft_move(key, game);
	else if (key == 65307)
		ft_clear_window("Finish program\n", game);
	return (0);
}

void	ft_move(int key, t_game *game)
{
	if (key == 'w')
		ft_up_move(game);
	else if (key == 'a')
		ft_left_move(game);
	else if (key == 's')
		ft_down_move(game);
	else
		ft_right_move(game);
}

void	ft_player_trap(int Nrow, int Ncol, char flag, t_game *game)
{
	int	row;
	int	col;

	if (game->trap.check == 1 && flag == 'T')
		game->trap.player_trap = 1;
	else if (game->trap.check == 0 && flag == 'T')
	{
		row = game->layout.player[1];
		col = game->layout.player[2];
		game->layout.map[Nrow][Ncol] = 't';
		if (game->layout.map[row][col] == 't')
			game->layout.map[row][col] = 'T';
		else
			game->layout.map[row][col] = '0';
		game->moves++;
		game->layout.player[1] = Nrow;
		game->layout.player[2] = Ncol;
	}
}

void	ft_close(char *str, int validate, t_game *game)
{
	int	row;
	int	col;
	int	x;

	x = 0;
	row = game->layout.player[1];
	col = game->layout.player[2];
	if (game->trap.player_trap == 1 || (game->trap.t_check == 1
			&& game->layout.map[row][col] == 't'))
		free(game->n_moves);
	if (validate == 1)
	{
		while (game->layout.map[x] != NULL)
			free(game->layout.map[x++]);
		free(game->layout.map);
	}
	ft_printf("%s", str);
	exit(1);
}

int	ft_clear_window(char*str, t_game *game)
{
	mlx_destroy_image(game->link, game->img.key);
	mlx_destroy_image(game->link, game->img.exit);
	mlx_destroy_image(game->link, game->img.floor);
	mlx_destroy_image(game->link, game->img.player);
	mlx_destroy_image(game->link, game->trap.trap);
	mlx_destroy_image(game->link, game->trap.t_trap);
	mlx_destroy_image(game->link, game->img.wdl);
	mlx_destroy_image(game->link, game->img.wdr);
	mlx_destroy_image(game->link, game->img.wdw);
	mlx_destroy_image(game->link, game->img.wlf);
	mlx_destroy_image(game->link, game->img.wmid);
	mlx_destroy_image(game->link, game->img.wrg);
	mlx_destroy_image(game->link, game->img.wul);
	mlx_destroy_image(game->link, game->img.wup);
	mlx_destroy_image(game->link, game->img.wur);
	mlx_clear_window(game->link, game->win);
	mlx_destroy_window(game->link, game->win);
	mlx_destroy_display(game->link);
	free(game->link);
	ft_close(str, 1, game);
	return (0);
}
