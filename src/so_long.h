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

# define WIDTH 72
# define HEIGHT 72

// assets
# define PLAYER_FRONT "./assets/bonecodefrentex.png"
# define MAPS "./maps/"

typedef struct s_position
{
	int				x;
	int				y;
}					s_position;

typedef struct s_map
{
	char			**matrice;
	int				player;
	int				columns;
	int				rows;
	int				coin;
	int				exits;
	int				floor;
	int				walls;

}					t_map;

typedef struct s_tiles
{
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;

}					t_tiles;

typedef struct s_game
{
	mlx_t			*mlx;
	int				fd;
	t_map			map;
	t_tiles			tiles;
	bool			map_alloc;

}					t_game;

void				initialize_value(t_game *game);
void				init_map_matrice(t_game *game);
void				init_layer(t_game *game);
void				init_mlx(t_game *game);
void				ft_error(char *message, t_game *game);
void				ft_free_map(t_game *game);

#endif
