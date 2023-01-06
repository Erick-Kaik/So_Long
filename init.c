/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:56:49 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/08 16:11:09 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_init(t_game *game)
{
	game->link = mlx_init();
	game->win = mlx_new_window(game->link, game->layout.column * PIXEL_MAP,
			game->layout.row * PIXEL_MAP, "So_long");
	mlx_loop_hook(game->link, ft_render, game);
	mlx_key_hook(game->win, ft_key_press, game);
	mlx_hook(game->win, 17, 0, ft_press_x, game);
	mlx_loop(game->link);
	return (0);
}
