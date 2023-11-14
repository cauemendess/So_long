/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:40:23 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/14 13:04:14 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_counter(t_game *game)
{
	char				*move_counter;
	static mlx_image_t	*counter;

	move_counter = NULL;
	if (counter)
		mlx_delete_image(game->mlx, counter);
	move_counter = ft_itoa(game->moves);
	mlx_put_string(game->mlx, "Moves -> ", 0, 10);
	counter = mlx_put_string(game->mlx, move_counter, 90, 10);
	free(move_counter);
	ft_printf("Movements: %d\n", game->moves++);
}
