#include "so_long.h"

void	keyhooks(mlx_key_data_t keydata, void *param)
{
	param = NULL;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

void	image_init(mlx_t *mlx)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(PLAYER_FRONT);
	img = mlx_texture_to_image(mlx, texture);
	mlx_key_hook(mlx, &keyhooks, NULL);
	mlx_image_to_window(mlx, img, HEIGHT / 2, WIDTH / 2);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
}
void	init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	image_init(mlx);
}

void	arguments_check(int ac, char **av)
{
	int map_param_len;
	
	if(ac > 2)
		ft_error("Muitos argumentos\n");
	if(ac < 2)
		ft_error("Poucos argumentos\n");
	map_param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_param_len - 4], ".ber", 4))
		ft_error("Tem que ter (.ber) no arquivo\n");
	
}


int	main(int argc, char **argv)
{
	t_game game;
	game.fd = open(argv[1], O_RDONLY);
	arguments_check(argc, argv);
	initialize_value(&game);
	init_map_matrice(&game);
	init_layer(&game);

	return (EXIT_SUCCESS);
}