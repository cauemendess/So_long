#include "so_long.h"

void	initialize_value(t_game *game)
{
	game->map.player = 0;
	game->map.columns = 0;
	game->map.rows = 0;
	game->map.coin = 0;
	game->map.exits = 0;
	game->map.floor = 0;
	game->map.walls = 0;
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
	while (game->map.matrice[i++])
		game->map.rows++;
	if (!(game->map.matrice[0]))
		ft_error("Mapa vazio!\n", game);
	free(map);
	close(game->fd);
}
