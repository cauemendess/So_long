/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:39 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/08 17:09:25 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_texture(game->tiles.floor);
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_texture(game->tiles.walls);
	mlx_terminate(game->mlx);
}
