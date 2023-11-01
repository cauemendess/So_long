/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:19 by csilva-m          #+#    #+#             */
/*   Updated: 2023/10/31 16:43:25 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_matrice(t_game *game);
void	define_map_struct(t_game *game, char c, int y, int x);
int		columns_len(t_game *game);
void	validate_map(t_game *game);
void	check_walls(t_game *game);

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
			x++;
			define_map_struct(game, game->map.matrice[y][x], y, x);
		}
		y++;
	}
	columns_len(game);
	validate_map(game);
	check_walls(game);
	check_path(game);
}

void	define_map_struct(t_game *game, char c, int y, int x)
{
	if (ft_strchr("PEC01", c) == NULL)
		ft_error("Caractér inválido encontrado\n", game);
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
			ft_error("O mapa tá aberto na primeira coluna\n", game);
		else if (game->map.matrice[i][game->map.columns - 1] != CHAR_WALL)
			ft_error("O mapa tá aberto na ultima coluna\n", game);
		i++;
	}
	while (j < game->map.columns)
	{
		if (game->map.matrice[0][j] != CHAR_WALL)
			ft_error("O mapa tá aberto na primeira linha\n", game);
		else if (game->map.matrice[game->map.rows - 1][j] != CHAR_WALL)
			ft_error("O mapa tá aberto na ultima linha\n", game);
		j++;
	}
}

void	validate_map(t_game *game)
{
	if (!(game->map.player == 1 && game->map.exits == 1 && game->map.coin >= 1
			&& game->map.floor >= 1 && game->map.walls >= 1
			&& game->map.rows >= 3 && game->map.columns >= 3))
		ft_error("Mapa inválido!\n", game);
}
