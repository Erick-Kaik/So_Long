/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekaik-ne <ekaik-ne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:37:10 by ekaik-ne          #+#    #+#             */
/*   Updated: 2022/07/13 20:45:43 by ekaik-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_check(char *filename, t_game *game)
{
	int		map_open;
	char	*line;

	ft_validate_ber(&map_open, filename, game);
	line = get_next_line(map_open);
	while (line != NULL)
	{
		if (ft_look_layout(line, game) == 1)
			game->layout.row++;
		else
			ft_close("Error\nMap Invalid\n", 0, game);
		free(line);
		line = get_next_line(map_open);
	}
	free(line);
	close(map_open);
	if (game->layout.row != 0 && game->layout.column != 0
		&& game->layout.row != game->layout.column)
		ft_fill_map(filename, game);
	else
		ft_close("Error\nInvalid Map\n", 0, game);
	ft_verify_border(game);
}

void	ft_validate_ber(int *map_open, char *filename, t_game *game)
{
	if (ft_check_ber(filename, ".ber", game) == 1)
		*map_open = open(filename, O_RDONLY);
	else
	{
		*map_open = -1;
		ft_close("Error\nInvalid Extension\n", 0, game);
	}
}

int	ft_check_ber(const char *str, char *find, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	ft_load_struct(game);
	if (str[x] == '\0')
		return (0);
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x + y] == find[y] && str[x + y] != '\0')
		{
			if (find[y + 1] == '\0' && str[x + y + 1] == '\0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_press_x(t_game *game)
{
	ft_clear_window("Finish Game\n", game);
	return (0);
}

void	ft_check_map(t_game *game, int x)
{
	game->layout.map[x] = NULL;
	if (game->layout.collect < 1 || game->layout.player[0] != 1
		|| game->layout.goal != 1)
		ft_close("Error\nMap Invalid\n", 0, game);
}
