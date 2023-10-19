#include "so_long.h"

void	init_map_matrice(t_game *game);
void	define_map_struct(t_game *game, char c);
int		check_colluns(t_game *game);
void	validate_map(t_game *game);

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
			define_map_struct(game, game->map.matrice[y][x]);
			x++;
		}
		y++;
	}
	validate_map(game);
}

void	define_map_struct(t_game *game, char c)
{
	if (ft_strchr("PEC01", c) == NULL)
		//Deve fechar o mapa e dar free na matriz
		ft_error("Caractér inválido encontrado\n", game);
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

int	check_colluns(t_game *game)
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

void	validate_map(t_game *game)
{
	if (!(game->map.player == 1 && game->map.exits == 1 && game->map.coin >= 1
		&& game->map.floor >= 1 && game->map.walls >= 1 && game->map.rows >= 2
		&& check_colluns(game) == 1))
		ft_error("Mapa inválido\n", game);
}
