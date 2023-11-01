/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:50 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/01 14:43:58 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game);

t_bool	flood_fill(t_game *game, int y, int x)
{
	t_bool		found_exit;

	found_exit = FALSE;
	if (x >= 0 || y >= 0 || y < game->map.rows || x < game->map.columns)
	{
		if (game->map.matrice_fill[y][x] == CHAR_WALL
			|| game->map.matrice_fill[y][x] == 'X')
			return (FALSE);
		if (game->map.matrice_fill[y][x] == CHAR_FLOOR)
			game->map.matrice_fill[y][x] = 'X';
		else if (game->map.matrice_fill[y][x] == CHAR_COIN)
			game->map.matrice_fill[y][x] = 'X';
		else if (game->map.matrice_fill[y][x] == 'E')
			found_exit = TRUE;
		if (flood_fill(game, y, x + 1) || flood_fill(game, y, x - 1)
			|| flood_fill(game, y + 1, x) || flood_fill(game, y - 1, x))
			found_exit = TRUE;
	}

	return (found_exit);
}

void	check_path(t_game *game)
{
	if (!flood_fill(game, game->map.player_pos.y, game->map.player_pos.x))
	{
		print_map(game);
		ft_error("Não existe um caminho até a saída\n", game);
	}
	print_map(game);
	ft_free_map(game, 0);
}
// Função de teste
void	print_map(t_game *game)
{
	for (int i = 0; i < game->map.rows; i++)
	{
		for (int j = 0; j < game->map.columns; j++)
		{
			printf("%c ", game->map.matrice_fill[i][j]);
		}
		printf("\n");
	}
}
