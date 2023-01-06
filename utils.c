/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:59 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/08 11:05:48 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_load_struct(t_game *game)
{
	game->layout.row = 0;
	game->layout.column = 0;
	game->layout.player[0] = 0;
	game->layout.player[1] = 0;
	game->layout.player[2] = 0;
	game->layout.collect = 0;
	game->layout.goal = 0;
	game->trap.player_trap = 0;
	game->trap.count = 1;
	game->trap.t_count = 0;
	game->trap.t_check = 0;
	game->moves = 0;
	game->img.create = 0;
	game->score = 0;
	game->open = 0;
}

void	ft_validate_move(int row, int col, t_game *game)
{
	if (game->layout.map[row][col] == '1')
		return ;
	else if (game->layout.map[row][col] == '0')
		ft_change_map(row, col, game->layout.map[row][col], game);
	else if (game->layout.map[row][col] == 'C')
		ft_change_map(row, col, game->layout.map[row][col], game);
	else if (game->layout.map[row][col] == 'E'
		&& game->score != game->layout.collect)
		return ;
	else if (game->layout.map[row][col] == 'E'
		&& game->score == game->layout.collect)
		ft_change_map(row, col, game->layout.map[row][col], game);
	else if (game->layout.map[row][col] == 'T')
		ft_player_trap(row, col, game->layout.map[row][col], game);
}

void	ft_change_map(int Nrow, int Ncol, char flag, t_game *game)
{
	int	row;
	int	col;

	row = game->layout.player[1];
	col = game->layout.player[2];
	if (game->trap.t_check == 1 && game->layout.map[row][col] == 't')
		return ;
	else if (game->layout.map[row][col] == 't')
		game->layout.map[row][col] = 'T';
	else
		game->layout.map[row][col] = '0';
	game->layout.map[Nrow][Ncol] = 'P';
	game->moves++;
	game->layout.player[1] = Nrow;
	game->layout.player[2] = Ncol;
	if (flag == 'C')
		game->score++;
	else if (flag == 'E')
		ft_clear_window("Finish Game :)\n", game);
}

char	*ft_get_xpm_file(char *file, int count)
{
	char	*get_xpm;
	char	*xpm_file;
	char	*itoa;

	itoa = ft_itoa(count);
	get_xpm = ft_strjoin(file, itoa);
	xpm_file = ft_strjoin(get_xpm, ".xpm");
	free(get_xpm);
	free(itoa);
	return (xpm_file);
}

void	ft_check_trap(t_game *game, int l, char flag)
{
	if (flag == 'T')
		ft_trap(game, 10, l);
	else if (flag == 't' && game->trap.t_check == 1)
		ft_anim_player_trap(game, 14, l);
	else if (flag == 't')
		ft_anim_player_trap(game, 14, l);
}
