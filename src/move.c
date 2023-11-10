/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:26 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/10 16:23:23 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(t_game *game, int x, int y, int direction);
t_bool	verify_content(t_game *game, int x, int y);

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, 0, -WIDTH, 0);
	if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, 0, WIDTH, 1);
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, WIDTH, 0, 2);
	if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(game, -WIDTH, 0, 3);
}

void	movement(t_game *game, int x, int y, int direction)
{
	int	px;
	int	py;
	int	i;

	i = direction;
	direction = i;
	px = game->player[0].image->instances[0].x + x;
	py = game->player[0].image->instances[0].y + y;
	if (verify_content(game, px, py))
	{
		//while (i < 4)
		//{
		//	if (i == direction){
		//		game->img.player->instances[direction].enabled = 1;
		//		i++;
		//		continue ;
		//	}
		//	game->img.player->instances[direction].enabled = 0;
		//	i++;
		//}
		game->player[0].image->instances[0].y = py;
		game->player[0].image->instances[0].x = px;
	}
}
t_bool	verify_content(t_game *game, int x, int y)
{
	int	i;
	int	xw;
	int	yw;

	i = 0;
	printf("fora\n");
	while (i < game->map.walls)
	{
		printf("%d\n", i);
		xw = game->img.wall->instances[i].x;
		yw = game->img.wall->instances[i].y;
		if (x == xw && y == yw)
		{
			printf("Teste\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}
