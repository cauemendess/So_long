/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:15 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/08 17:11:11 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_png(t_game *game, mlx_texture_t **texture, mlx_image_t **img,
			char *path);
void	render_floor(t_game *game);
void	my_image_to_window(t_game *game, mlx_image_t *mlx_img, int x, int y);
void	render_map(t_game *game);

// Tem 	que organizar
void	image_init(t_game *game)
{
	place_png(game, &game->tiles.floor, &game->img.floor, FLOOR_PNG);
	place_png(game, &game->tiles.walls, &game->img.wall, WALL_PNG);
	render_floor(game);
	render_map(game);
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
			my_image_to_window(game, game->img.floor, x, y);
			x++;
		}
		y++;
	}
}
// Tá errado
void	my_image_to_window(t_game *game, mlx_image_t *mlx_img, int x, int y)
{
	mlx_image_to_window(game->mlx, mlx_img, x * WIDTH, y * HEIGHT);
	if (!mlx_img)
		ft_error("Não tem imagem meu nobre", game);
}
// Ainda não ta funfando
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
				mlx_image_to_window(game->mlx, game->img.wall, x * WIDTH, y * HEIGHT);
			//else if (game->map.matrice[y][x] == CHAR_COIN)
			//	render_coin(game);
			//else if (game->map.matrice[y][x] == CHAR_EXIT)
			//	render_exit();
			//else if (game->map.matrice[y][x] == CHAR_PLAYER)
			//	render_player();
		}
	}
}

//void render_coin(t_game *game)
//{
	
//}
