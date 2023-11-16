/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:05 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/16 11:23:00 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_value(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map.player = 0;
	game->map.columns = 0;
	game->map.rows = 0;
	game->map.coin = 0;
	game->map.exits = 0;
	game->map.floor = 0;
	game->map.walls = 0;
	game->map.enemy = 0;
	game->count = 0;
	game->moves = 1;
	return (game);
}

void	init_map_matrice(t_game *game)
{
	char	*map;
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		temp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(temp);
	}
	game->map.matrice = ft_split(map, '\n');
	game->map.matrice_fill = ft_split(map, '\n');
	while (game->map.matrice[i++])
		game->map.rows++;
	free(map);
	if (!(game->map.matrice[0]))
		ft_error("Error, empty map!\n", game);
	close(game->fd);
}
