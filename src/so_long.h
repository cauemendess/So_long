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
# define EMPTY '0'
# define EXIT 'E'
# define ITEM 'C'

# define WIDTH 650
# define HEIGHT 650
// assets
# define PLAYER_FRONT "./assets/bonecodefrentex.png"
# define MAPS "./maps/"

typedef struct s_multi
{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_game
{
	mlx_t		*mlx;
	int			fd;

}				t_game;


#endif
