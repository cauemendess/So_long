/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:14 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/16 14:42:28 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define CHAR_PLAYER 'P'
# define CHAR_WALL '1'
# define CHAR_FLOOR '0'
# define CHAR_EXIT 'E'
# define CHAR_COIN 'C'
# define CHAR_ENEMY 'F'

# define WIDTH 64
# define HEIGHT 64

// assets
# define WALL_PNG "./assets/wall.png"
# define FLOOR_PNG "./assets/floor.png"
# define COIN_PNG "./assets/coin.png"
# define EXIT_PNG "./assets/exit.png"
# define FRONT_PNG "./assets/snorlax.png"
# define ENEMY_PNG "./assets/gastly.png"
# define MAPS "./maps/"

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_mult
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
	int				x;
	int				y;
}					t_mult;

typedef struct s_image
{
	mlx_image_t		*player;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*enemy;

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
	int				enemy;
	t_pos			player_pos;

}					t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	int				fd;
	char			*map_name;
	t_map			map;
	t_image			img;
	int				count;
	t_mult			coin[100000];
	t_mult			player[1];
	int				moves;

}					t_game;

t_game				*initialize_value(void);
void				init_map_matrice(t_game *game);
void				check_path(t_game *game);
void				init_layer(t_game *game);
void				flood_fill(t_game *game, int y, int x);
void				init_mlx(t_game *game);
void				image_init(t_game *game);
void				place_png(t_game *game, mlx_image_t **image, char *path);
void				render_floor(t_game *game);
void				render_map(t_game *game);
void				render_coin(t_game *game, int x, int y, int *count);
void				render_exit(t_game *game, int x, int y);
void				keyhooks(mlx_key_data_t keydata, void *param);
void				delete_image(t_game *game);
void				ft_error(char *message, t_game *game);
void				ft_error_message(char *message);
void				touch_enemy(t_game *game, int x, int y);
void				ft_free_map(char **matriz);
void				write_counter(t_game *game);
void				ft_finish(char *message, t_game *game);
t_bool				verify_walls(t_game *game, int x, int y);
void				movement(t_game *game, int x, int y);
void				collect_item(t_game *game, int x, int y);
void				exit_game(t_game *game, int x, int y);
void				define_map_struct(t_game *game, char c, int y, int x);
int					columns_len(t_game *game);
void				validate_map(t_game *game);
void				check_walls(t_game *game);

#endif
