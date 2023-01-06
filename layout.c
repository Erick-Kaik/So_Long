/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:36:48 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 16:44:18 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_look_layout(char *line, t_game *game)
{
	int	x;

	x = 0;
	while (ft_strchr("01CEPT", line[x]) && line[x] != '\0')
	{
		if (line[x] == 'C')
			game->layout.collect++;
		else if (line[x] == 'P')
		{
			game->layout.player[0]++;
			game->layout.player[1] = game->layout.row;
			game->layout.player[2] = x;
		}
		else if (line[x] == 'E')
			game->layout.goal++;
		x++;
	}
	if (x != 0 && (line[x] == '\n' || line[x] == '\0'))
	{
		game->layout.column = x;
		return (1);
	}
	return (0);
}

void	ft_fill_map(char *filename, t_game *game)
{
	int		map_open;
	int		x;
	int		y;
	char	*line;

	x = 0;
	map_open = open(filename, O_RDONLY);
	game->layout.map = (char **)malloc(sizeof(char *) * (game->layout.row + 1));
	line = get_next_line(map_open);
	while (x < game->layout.row && line != NULL)
	{
		y = 0;
		game->layout.map[x] = (char *)malloc(1 * (game->layout.column + 1));
		while (ft_strchr("01CEPT", line[y]) && line[y] != '\0')
		{
			game->layout.map[x][y] = line[y];
			y++;
		}
		game->layout.map[x++][y] = '\0';
		free(line);
		line = get_next_line(map_open);
	}
	free(line);
	close(map_open);
	ft_check_map(game, x);
}

void	ft_verify_border(t_game *game)
{
	if (ft_verify_up_down(game) == 1 && ft_verify_right_left(game) == 1)
		ft_init(game);
	else
		ft_close("Error\nMap Invalid\n", 0, game);
}

int	ft_verify_up_down(t_game *game)
{
	int	x;

	x = 0;
	while (game->layout.map[0][x] == '1'
		&& game->layout.map[game->layout.row - 1][x] == '1')
		x++;
	if (x == game->layout.column)
		return (1);
	else
		return (0);
}

int	ft_verify_right_left(t_game *game)
{
	int	x;
	int	verify;

	x = 1;
	while (x < game->layout.row)
	{
		if (game->layout.map[x][0] == '1'
			&& game->layout.map[x][game->layout.column - 1] == '1')
			verify = 1;
		else
		{
			verify = 0;
			break ;
		}
		x++;
	}
	if (verify == 1)
		return (1);
	else
		return (0);
}
