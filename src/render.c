/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:15 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/07 18:57:45 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_png_to_img(t_game *game, mlx_image_t *img, char *path);
void	render_floor(t_game *game);
void	my_image_to_window(t_game *game, mlx_image_t *mlx_img, int x, int y);

//void	place_texture(t_game *game)
//{
//	//colocar "azulejo" na "parede"
//	place_png_to_img(game, game->img.floor, FLOOR_PNG);
//	render_floor(game);
//}

//void	place_png_to_img(t_game *game, mlx_image_t *img, char *path)
//{
//	mlx_texture_t	*my_texture;

//	my_texture = mlx_load_png(path);
//	if (!my_texture)
//		ft_error("Deu problema na imagem", game);
//	img = mlx_texture_to_image(game->mlx, my_texture);
//	mlx_delete_texture(my_texture);
//}

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

void	my_image_to_window(t_game *game, mlx_image_t *mlx_img, int x, int y)
{
	mlx_image_to_window(game->mlx, mlx_img, x * WIDTH, y * HEIGHT);
	if (!mlx_img)
		ft_error("Não tem imagem meu nobre", game);
}

//void	render_map(t_game *game)
//{
//	int y;
//	int x;

//	y = -1;
//	while(++y < game->map.columns)
//	{
//		while(++x < game->map.rows)
//		{
//			if(game->map.matrice[y][x] == CHAR_WALL)
//				render_wall();
//			else if (game->map.matrice[y][x] == CHAR_COIN)
//				render_coin();
//			else if (game->map.matrice[y][x] == CHAR_EXIT)
//				render_exit();
//		}
//	}
//}