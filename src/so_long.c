#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	param = NULL;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

int32_t	main(void)
{
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Test", true);

	mlx_texture_t *texture = mlx_load_png("./assets/bonecodefrentex.png");

	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_image_to_window(mlx, img, 30, 19);

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
