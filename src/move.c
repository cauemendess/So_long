/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:26 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/13 19:32:03 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	verify_walls(t_game *game, int x, int y);
void	movement(t_game *game, int x, int y);
void	collect_item(t_game *game, int x, int y);

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q) &&
		(keydata.action == MLX_PRESS))
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
		collect_item(game, x_player, y_player);
		game->player[0].image->instances[0].y = y_player;
		game->player[0].image->instances[0].x = x_player;
	}
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
		x_wall = game->img.wall->instances[i].x;
		y_wall = game->img.wall->instances[i].y;
		if (x == x_wall && y == y_wall)
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	collect_item(t_game *game, int x, int y)
{
	int i;
	int x_coin;
	int y_coin;

	x_coin = 0;
	y_coin = 0;
	i = 0;
	printf("Boa tarde\n");
	while (i < game->map.coin)
	{
		x_coin = game->coin[i].image->instances[0].x;
		y_coin = game->coin[i].image->instances[0].y;
		if (x == x_coin && y == y_coin
			&& game->coin[i].image->instances[0].enabled)
		{
			printf("%d\n", game->count);
			//if (x == game->map.exit_pos.x && y == game->map.exit_pos.y
			//	&& game->count == 1)
			//{
			//	ft_error("Obrigado por jogar!\n", game);
			//}
			game->coin[i].image->instances[0].enabled = 0;
			game->count--;
			return ;
		}
		i++;
	}
}