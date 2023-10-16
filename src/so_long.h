#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PLAYER 'P'
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COIN 'C'

# define WIDTH 650
# define HEIGHT 650
// assets
# define PLAYER_FRONT "./assets/bonecodefrentex.png"
# define MAPS "./maps/"

typedef struct s_map
{
	char	**matriz;
	int		player;
	int		colluns;
	int		rolls;
	int		coin;
	int		exits;
	int		floor;
	int		walls;

}			t_map;

typedef struct s_game
{
	mlx_t	*mlx;
	int		fd;
	t_map	map;

}			t_game;

void		initialize_value(t_game *game);
void		validate_map(t_game *game);
void		init_mlx(void);

#endif
