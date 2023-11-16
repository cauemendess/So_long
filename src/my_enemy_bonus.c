/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:47 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/16 11:31:52 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	touch_enemy(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->map.enemy)
	{
		if (x == game->img.enemy->instances[i].x
			&& y == game->img.enemy->instances[i].y)
		{
			delete_image(game);
			ft_finish("You touch an enemy :(\n", game);
		}
		i++;
	}
}
