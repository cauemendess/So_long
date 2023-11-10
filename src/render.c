/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:15 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/10 16:46:06 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_png(t_game *game, mlx_texture_t **texture, mlx_image_t **img,
			char *path);
void	render_floor(t_game *game);

void	render_map(t_game *game);
void	render_coin(t_game *game, int x, int y);
void	render_player(t_game *game, int x, int y);

void	place_mult_png(t_game *game, char *path, int choise);

// Tem 	que organizar
void	image_init(t_game *game)
{
	place_png(game, &game->tiles.floor, &game->img.floor, FLOOR_PNG);
	place_png(game, &game->tiles.walls, &game->img.wall, WALL_PNG);
	place_png(game, &game->tiles.exit, &game->img.exit, EXIT_PNG);
	place_mult_png(game, COIN_PNG, 1);
	place_mult_png(game, FRONT_PNG, 2);
	place_mult_png(game, BACK_PNG, 2);
	place_mult_png(game, LEFT_PNG, 2);
	place_mult_png(game, RIGHT_PNG, 2);
	render_floor(game);
	render_map(game);
}

void	place_mult_png(t_game *game, char *path, int choise)
{
	int	i;
	int	j;

	i = -1;
	if (choise == 1)
	{
		j = 0;
		while (++i < game->map.coin)
		{
			game->coin[i].texture = mlx_load_png(path);
			game->coin[i].image = mlx_texture_to_image(game->mlx,
														game->coin[i].texture);
		}
	}
	if (choise == 2)
	{
		game->player[j].texture = mlx_load_png(path);
		game->player[j].image = mlx_texture_to_image(game->mlx,
				game->player[j].texture);
		j++;
	}
}

void	place_png(t_game *game, mlx_texture_t **texture, mlx_image_t **image,
		char *path)
{
	*texture = mlx_load_png(path);
	*image = mlx_texture_to_image(game->mlx, *texture);
}

// Tá funfando
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
			mlx_image_to_window(game->mlx, game->img.floor, x * WIDTH, y
					* HEIGHT);
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
				mlx_image_to_window(game->mlx, game->img.wall, x * WIDTH, y
						* HEIGHT);
			else if (game->map.matrice[y][x] == CHAR_COIN)
				render_coin(game, x * WIDTH, y * HEIGHT);
			else if (game->map.matrice[y][x] == CHAR_EXIT)
				mlx_image_to_window(game->mlx, game->img.exit, x * WIDTH, y
						* HEIGHT);
			else if (game->map.matrice[y][x] == CHAR_PLAYER)
				render_player(game, x * WIDTH, y * HEIGHT);
		}
	}
}

void	render_player(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->player[0].image, x, y);
	mlx_image_to_window(game->mlx, game->player[1].image, x, y);
	mlx_image_to_window(game->mlx, game->player[2].image, x, y);
	mlx_image_to_window(game->mlx, game->player[3].image, x, y);
	game->player->image[1].enabled = 0;
	game->player->image[2].enabled = 0;
	game->player->image[3].enabled = 0;
}

void	render_coin(t_game *game, int x, int y)
{
	int i = 0;
	while (i < game->map.coin)
	{
		mlx_image_to_window(game->mlx, game->coin[i].image, x, y);
		i++;
	}
}