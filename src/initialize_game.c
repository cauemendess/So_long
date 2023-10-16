#include "so_long.h"

void initialize_value(t_game *game)
{
	game->map.player = 0;
	game->map.colluns = 0;
	game->map.rolls = 0;
	game->map.coin = 0;
	game->map.exits = 0;
	game->map.floor = 0;
	game->map.walls = 0;
}
