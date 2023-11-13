/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:07:39 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/13 16:52:48 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_image(game->mlx, game->coin->image);
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.exit);
	mlx_delete_image(game->mlx, game->player->image);
	mlx_terminate(game->mlx);
}
