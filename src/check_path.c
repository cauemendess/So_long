/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:50 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/14 16:59:46 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int y, int x)
{
	if (game->map.matrice_fill[y][x] == '1'
		|| game->map.matrice_fill[y][x] == 'X'
		|| game->map.matrice_fill[y][x] == 'I')
		return ;
	game->map.matrice_fill[y][x] = 'X';
	flood_fill(game, y - 1, x);
	flood_fill(game, y + 1, x);
	flood_fill(game, y, x - 1);
	flood_fill(game, y, x + 1);
}

void	check_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrice_fill[i])
	{
		j = 0;
		while (game->map.matrice_fill[i][j])
		{
			if (game->map.matrice_fill[i][j] == CHAR_EXIT
				|| game->map.matrice_fill[i][j] == CHAR_COIN)
				ft_error("There is no way to the exit.\n", game);
			j++;
		}
		i++;
	}
	ft_free_map(game->map.matrice_fill);
}
