#include "so_long.h"

void print_map(char **str, t_game *game);

bool	flood_fill(t_game *game, t_pos curr)
{
	bool	found_exit;
	int		coins;

	found_exit = false;
	coins = 0;
	if (curr.x < 0 || curr.x >= game->map.columns || curr.y < 0
		|| curr.y >= game->map.rows)
	{
		return (false);
	}
	//if (game->map.matrice_fill[curr.y][curr.x] == CHAR_WALL)
	//	found_exit = false;
	//else if (game->map.matrice_fill[curr.y][curr.x] == CHAR_COIN)
	//	coins++;
	//else if (game->map.matrice_fill[curr.y][curr.x] == CHAR_EXIT)
	//	found_exit = true;
	game->map.matrice_fill[curr.y][curr.x] = CHAR_VISITED;
	system("clear");
	print_map(game->map.matrice_fill, game);
	sleep(1);
	flood_fill(game, (t_pos){curr.x + 1, curr.y});
	flood_fill(game, (t_pos){curr.x - 1, curr.y});
	flood_fill(game, (t_pos){curr.x, curr.y + 1});
	flood_fill(game, (t_pos){curr.x, curr.y - 1});
	return (coins == game->map.coin && found_exit);
}

void	check_path(t_game *game)
{
	flood_fill(game, game->map.player_pos);
	//if (!flood_fill(game, game->map.player_pos))
	//{
	//	printf("%d", flood_fill(game, game->map.player_pos));
	//	ft_error("Não existe um caminho até a saída\n", game);
	//}
	ft_free_map(game, 0);
}

void print_map(char **str, t_game *game)
{
	for(int i = 0 ;i < game->map.columns; i++)
	{
		for(int j=0 ;j < game->map.rows; j++)
		{
			printf("%c ", str[i][j]);
		}
		printf("\n");
	}
}