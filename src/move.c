/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:26 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/12 19:06:20 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, int x, int y);
t_bool	verify_walls(t_game *game, int x, int y);
void	collect_item(t_game *game, int x, int y);

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, 0, -WIDTH);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, 0, WIDTH);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, WIDTH, 0);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, -WIDTH, 0);
}

void	movement(t_game *game, int x, int y)
{
	int	x_player;
	int	y_player;
	
	x_player = game->player[0].image->instances[0].x + x;
	y_player = game->player[0].image->instances[0].y + y;
	if (verify_walls(game, x_player, y_player))
	{
		game->player[0].image->instances[0].y = y_player;
		game->player[0].image->instances[0].x = x_player;
	}
	collect_item(game, x_player, y_player);
	//finish(game, x_player, y_player);
}
t_bool	verify_walls(t_game *game, int x, int y)
{
	int	i;
	int	x_wall;
	int	y_wall;

	x_wall = 0;
	y_wall = 0;
	i = 0;
	while (i < game->map.walls)
	{
		//printf("%d\n", game->map.walls);
		x_wall = game->img.wall->instances[i].x;
		y_wall = game->img.wall->instances[i].y;
		if (x == x_wall && y == y_wall)
			return (FALSE);
		i++;
	}
	collect_item(game, x, y);
	return (TRUE);
}

void	collect_item(t_game *game, int x, int y)
{
	int	i;
	int	coin_x;
	int	coin_y;

	i = -1;
	coin_x = 0;
	coin_y = 0;
	while (++i < game->map.coin)
	{
		coin_x = game->coin[i].image->instances[0].x;
		coin_y = game->coin[i].image->instances[0].y;
		printf("Entrou\n");
		if (x == coin_x && y == coin_x)
		{
			printf("ACHOU COLETAVEL\n");
			game->coin[i].image->enabled = 0;
		}
	}
}
