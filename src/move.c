/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:26 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/09 17:22:42 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		game->img.player->instances[0].y -= WIDTH;
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		game->img.player->instances[0].y += WIDTH;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		game->img.player->instances[0].x += WIDTH;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		game->img.player->instances[0].x -= WIDTH;

}
