#include "so_long.h"

void	ft_error_message(char* message)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	exit(1);
}


void	ft_error(char *message, t_game *game)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	if(game->map.matrice != NULL)
		ft_free_map(game);
	exit(1);			
}

void	ft_free_map(t_game *game)
{
	int i;
	i = 0;
	while (i < game->map.rows)
		free(game->map.matrice[i++]);
	free(game->map.matrice);
}