/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:15 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/14 20:17:12 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			mlx_image_to_window(game->mlx, game->img.floor, \
			x * WIDTH, y * HEIGHT);
			x++;
		}
		y++;
	}
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.columns)
		{
			if (game->map.matrice[y][x] == CHAR_WALL)
				mlx_image_to_window(game->mlx, game->img.wall, x * WIDTH, y \
				* HEIGHT);
			else if (game->map.matrice[y][x] == CHAR_COIN)
				render_coin(game, x * WIDTH, y * HEIGHT, &game->count);
			else if (game->map.matrice[y][x] == CHAR_EXIT)
				render_exit(game, x, y);
			else if (game->map.matrice[y][x] == CHAR_PLAYER)
				mlx_image_to_window(game->mlx, game->player[0].image, \
				x * WIDTH, y * HEIGHT);
			else if (game->map.matrice[y][x] == CHAR_ENEMY)
				mlx_image_to_window(game->mlx, game->img.enemy, x * WIDTH, \
				y * HEIGHT);
		}
	}
}

void	render_exit(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img.exit, x * WIDTH, y * HEIGHT);
	game->img.exit->enabled = 0;
}

void	render_coin(t_game *game, int x, int y, int *count)
{
	place_png(game, &game->coin[*count].image, COIN_PNG);
	mlx_image_to_window(game->mlx, game->coin[*count].image, x, y);
	(*count)++;
}
