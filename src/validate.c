#include "so_long.h"

//void	init_layer(t_game *game)
//{
//	unsigned int x;
//	unsigned int y;
//	y = 0;
//	while (game->map.matrice[y])
//	{
//		x = 0;
//		while(game->map.matrice[x][y])
//		{
//			define_map_struct(game, game->map.matrice[x][y]);
//			x++;
//		}
//		y++;
//	}
	
//}

// o parâmetro c deve ser a posição desse char na matriz alocada
void	define_map_struct(t_game *game, char c)
{
	if (ft_strchr("PEC01", c) == NULL)
		//Deve fechar o mapa e dar free na matriz
		ft_error("Caractér inválido encontrado\n");
	if (c == CHAR_PLAYER)
		game->map.player++;
	else if (c == CHAR_EXIT)
		game->map.exits++;
	else if (c == CHAR_COIN)
		game->map.coin++;
	else if (c == CHAR_FLOOR)
		game->map.floor++;
	else if (c == CHAR_WALL)
		game->map.walls++;
}

void	validate_map(t_game *game)
{
	//char	c;
	char	*map;
	char	*line;
	//size_t	i;

	map = "";
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		//i = 0;
		map = ft_strjoin(map, line);
		//fazer uma função aqui para percorrer a matriz (tanto linhas como colunas)
		//while (i < ft_strlen(line))
		//{
		//	c = line[i];
		//	define_map_struct(game, line[i]);
		//	i++;
		//}
		game->map.rolls++;
		//printf("%zu\n", i);
		free(line);
	}
	game->map.matrice = ft_split(map, '\n');
	free(map);

	if (game->map.player == 1 && game->map.exits == 1 && game->map.coin >= 1
		&& game->map.floor >= 1 && game->map.walls >= 1 && game->map.rolls >= 2)
		init_mlx();
	else
		printf("Mapa inválido\n");
	close(game->fd);
}
