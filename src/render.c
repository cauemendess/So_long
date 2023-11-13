/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:15 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/13 19:43:25 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_png(t_game *game, mlx_image_t **image, char *path);
void	render_floor(t_game *game);

void	render_map(t_game *game);
void	render_coin(t_game *game, int x, int y, int *count);
void	render_player(t_game *game, int x, int y);

void	place_mult_png(t_game *game, char *path);

// Tem 	que organizar
void	image_init(t_game *game)
{
	place_png(game, &game->img.floor, FLOOR_PNG);
	place_png(game, &game->img.wall, WALL_PNG);
	place_png(game, &game->img.exit, EXIT_PNG);
	place_png(game, &game->player[0].image, FRONT_PNG);
	render_floor(game);
	render_map(game);
}


void	place_png(t_game *game, mlx_image_t **image, char *path)
{
	mlx_texture_t	*my_texture;

	my_texture = mlx_load_png(path);
	*image = mlx_texture_to_image(game->mlx, my_texture);
	mlx_delete_texture(my_texture);
}

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
				render_coin(game, x * WIDTH, y * HEIGHT, &game->count);
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
}

void	render_coin(t_game *game, int x, int y, int *count)
{
	place_png(game, &game->coin[*count].image, COIN_PNG);
	mlx_image_to_window(game->mlx, game->coin[*count].image, x, y);
	(*count)++;
}