/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/09 17:32:50 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CHAR_PLAYER 'P'
# define CHAR_WALL '1'
# define CHAR_FLOOR '0'
# define CHAR_EXIT 'E'
# define CHAR_COIN 'C'

# define WIDTH 64
# define HEIGHT 64

// assets
# define WALL_PNG "./assets/wall_pokemon.png"
# define FLOOR_PNG "./assets/floor_pokemon64.png"
# define COIN_PNG "./assets/colectable.png"
# define EXIT_PNG "./assets/exit_pokemon.png"
# define PLAYER_PNG "./assets/snorlax_side.png"
# define MAPS "./maps/"

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_image
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*coin;
	mlx_image_t		*exit;

}					t_image;

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_map
{
	char			**matrice;
	char			**matrice_fill;
	int				player;
	int				columns;
	int				rows;
	int				coin;
	int				exits;
	int				floor;
	int				walls;
	t_pos			player_pos;

}					t_map;

typedef struct s_tiles
{
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;

}					t_tiles;

typedef struct s_game
{
	mlx_t			*mlx;
	int				fd;
	char			*map_name;
	t_map			map;
	t_tiles			tiles;
	t_image			img;
	int				count;


}					t_game;

void				initialize_value(t_game *game);
void				init_map_matrice(t_game *game);
void				check_path(t_game *game);
void				init_layer(t_game *game);
void				init_mlx(t_game *game);
void				image_init(t_game *game);
void				render_floor(t_game *game);
void				place_texture(t_game *game);
void				keyhooks(mlx_key_data_t keydata, void *param);
void				delete_image(t_game *game);
void				ft_error(char *message, t_game *game);
void				ft_error_message(char *message);
void				ft_free_map(char **matriz);

#endif
