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

# define WIDTH 650
# define HEIGHT 650
// assets
# define PLAYER_FRONT "./assets/bonecodefrentex.png"
# define MAPS "./maps/"

typedef struct s_position
{
	int		x;
	int		y;
}			s_position;

typedef struct s_map
{
	char	**matrice;
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
void		ft_error(char *message);


#endif
