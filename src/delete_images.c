/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:39 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/12 15:04:30 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_image(t_game *game)
{
	mlx_delete_texture(game->tiles.floor);
	mlx_delete_texture(game->coin->texture);
	mlx_delete_texture(game->tiles.walls);
	mlx_delete_texture(game->tiles.exit);
	mlx_delete_texture(game->player->texture);
	mlx_terminate(game->mlx);
}
 