#include "so_long.h"

void	ft_error(char *message, t_game *game)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	if(game->map.matrice != NULL)
	{
		ft_putnbr_fd(game->map.rows, 1);
		ft_putstr_fd("Aqui\n", 1);

		ft_free_map(game);
	}
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