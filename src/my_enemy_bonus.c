/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:02:47 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/14 20:02:19 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	touch_enemy(t_game *game, int x, int y)
{
	if (x == game->img.enemy->instances[0].x
		&& y == game->img.enemy->instances[0].y)
	{
		delete_image(game);
		ft_finish("You touch an enemy :(\n", game);
	}
}
