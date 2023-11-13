/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:42:56 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/13 11:47:31 by csilva-m         ###   ########.fr       */
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
	if (game->map.matrice != NULL)
		ft_free_map(game->map.matrice);
	//if (game->map.matrice_fill != NULL)
	//	ft_free_map(game->map.matrice_fill);
	free(game);
	exit(1);
}

void	ft_free_map(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);

}

