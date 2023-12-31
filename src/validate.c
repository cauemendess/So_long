/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:19 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/16 14:29:24 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_layer(t_game *game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (game->map.matrice[y])
	{
		x = 0;
		while (game->map.matrice[y][x])
		{
			define_map_struct(game, game->map.matrice[y][x], y, x);
			++x;
		}
		y++;
	}
	columns_len(game);
	validate_map(game);
	check_walls(game);
	flood_fill(game, game->map.player_pos.y, game->map.player_pos.x);
	check_path(game);
}

void	define_map_struct(t_game *game, char c, int y, int x)
{
	if (ft_strchr("PEC01F", c) == NULL)
		ft_error("Error, invalid character found!\n", game);
	if (c == CHAR_PLAYER)
	{
		game->map.player++;
		game->map.player_pos = (t_pos){x, y};
	}
	else if (c == CHAR_EXIT)
		game->map.exits++;
	else if (c == CHAR_COIN)
		game->map.coin++;
	else if (c == CHAR_FLOOR)
		game->map.floor++;
	else if (c == CHAR_WALL)
		game->map.walls++;
	else if (c == CHAR_ENEMY)
		game->map.enemy++;
}

int	columns_len(t_game *game)
{
	size_t	first_line_len;
	size_t	i;

	i = 0;
	first_line_len = ft_strlen(game->map.matrice[0]);
	while (game->map.matrice[i] != NULL)
	{
		if (ft_strlen(game->map.matrice[i]) != first_line_len)
			return (0);
		i++;
	}
	game->map.columns = first_line_len;
	return (1);
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		if (game->map.matrice[i][0] != CHAR_WALL)
			ft_error("Error, the map is open in the first column!\n", game);
		else if (game->map.matrice[i][game->map.columns - 1] != CHAR_WALL)
			ft_error("Error, the map is open in the last column!\n", game);
		i++;
	}
	while (j < game->map.columns)
	{
		if (game->map.matrice[0][j] != CHAR_WALL)
			ft_error("Error, the map is open in the first line!\n", game);
		else if (game->map.matrice[game->map.rows - 1][j] != CHAR_WALL)
			ft_error("Error, the map is open in the last line!\n", game);
		j++;
	}
}

void	validate_map(t_game *game)
{
	if (!(game->map.player == 1 && game->map.exits == 1 && game->map.coin >= 1
			&& game->map.floor >= 1 && game->map.walls >= 1
			&& game->map.rows >= 3 && game->map.columns >= 3))
		ft_error("Invalid map!\n", game);
}
