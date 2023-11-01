/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:56 by csilva-m          #+#    #+#             */
/*   Updated: 2023/10/31 16:42:57 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *message)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	exit(1);
}

void	ft_error(char *message, t_game *game)
{
	ft_putstr_fd(message, STDOUT_FILENO);
	if (game->map.matrice != NULL || game->map.matrice_fill != NULL)
		ft_free_map(game, 1);
	exit(1);
}

void	ft_free_map(t_game *game, int choise)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.matrice_fill[i]);
		if (choise == 1)
			free(game->map.matrice[i]);
		i++;
	}
	free(game->map.matrice_fill);
	if (choise == 1)
		free(game->map.matrice);
}
