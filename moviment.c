/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moviment.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:36:20 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/07 17:43:34 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_up_move(t_game *game)
{
	int	row;
	int	column;

	row = game->layout.player[1];
	column = game->layout.player[2];
	ft_validate_move(row - 1, column, game);
}

void	ft_left_move(t_game *game)
{
	int	row;
	int	column;

	row = game->layout.player[1];
	column = game->layout.player[2];
	ft_validate_move(row, column - 1, game);
}

void	ft_down_move(t_game *game)
{
	int	row;
	int	column;

	row = game->layout.player[1];
	column = game->layout.player[2];
	ft_validate_move(row + 1, column, game);
}

void	ft_right_move(t_game *game)
{
	int	row;
	int	column;

	row = game->layout.player[1];
	column = game->layout.player[2];
	ft_validate_move(row, column + 1, game);
}
