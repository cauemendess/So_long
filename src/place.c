/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:03:29 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/16 14:02:46 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_game *game)
{
	place_png(game, &game->img.floor, FLOOR_PNG);
	place_png(game, &game->img.wall, WALL_PNG);
	place_png(game, &game->img.exit, EXIT_PNG);
	place_png(game, &game->img.enemy, ENEMY_PNG);
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
