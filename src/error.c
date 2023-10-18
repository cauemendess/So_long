#include "so_long.h"

void	ft_error(char *message)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

//void	ft_error_free(void)
//{
//	ft_putstr_fd(message, STDOUT_FILENO);
//	if (game->map.fill != NULL)
//		ft_free_map(game->map.fill, game->map.columns);
//	exit(EXIT_FAILURE);
//}

void	ft_free_map(t_game *game)
{
	int i;
	i = 0;
	while (i < game->map.rows)
		free(game->map.matrice[i++]);
	free(game->map.matrice);
}