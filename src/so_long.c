/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:43:09 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/07 19:03:29 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// devo fazer um arquivo só para eventos á partir dessa função
void	keyhooks(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(game->mlx);
	}
}

void	image_init(t_game *game)
{
	//mlx_image_t		*img;
	//mlx_texture_t	*texture;

	game->tiles.floor = mlx_load_png(FLOOR_PNG);
	game->img.floor = mlx_texture_to_image(game->mlx, game->tiles.floor);

	render_floor(game);
	
}

void delete_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_texture(game->tiles.floor);
	mlx_terminate(game->mlx);
}


void	init_mlx(t_game *game)
{
	//mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map.columns * WIDTH, game->map.rows * HEIGHT,
			"so long", true);
	if (!game->mlx)
	{
		ft_error("Erro na mlx. \n", game);
		exit(1);
	}
}

void	arguments_check(int ac, char **av)
{
	int	map_param_len;

	if (ac > 2)
		ft_error_message("Too many arguments!\n");
	if (ac < 2)
		ft_error_message("Too few arguments!\n");
	map_param_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_param_len - 4], ".ber", 4))
		ft_error_message("The file must to be a (.ber) file.\n");
}

int	main(int argc, char **argv)
{
	t_game game;
	
	game.map_name = argv[1];
	game.fd = open(game.map_name, O_RDONLY);
	arguments_check(argc, argv);
	initialize_value(&game);
	init_map_matrice(&game);
	init_layer(&game);
	init_mlx(&game);
	//place_texture(&game);
	image_init(&game);
	mlx_key_hook(game.mlx, &keyhooks, &game.mlx);
	mlx_loop(game.mlx);
	delete_image(&game);

	return (EXIT_SUCCESS);
}

//void my_image_to_window(t_game *game, mlx_image_t *mlx_image, int x, int y)
//{
//	mlx_image_to_window(game->mlx, mlx_image, x * WIDTH , y * HEIGHT);
//	if(!mlx_image)
//		ft_error("Erro na imagem.\n", game);
//}

//void	clean_all(t_game *game)
//{

//	// fazer um arquivo só para deletar coisas da tela
//	delete_all_images(game);
//	mlx_terminate(game->mlx);
//}