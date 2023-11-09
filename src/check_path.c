/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:50 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/09 17:33:14 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	flood_fill(t_game *game, int y, int x)
{
	t_bool	found_exit;

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
		ft_error("Não existe um caminho até a saída\n", game);
}

