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

void	validate(char *map)
{
	char	c;
	char	*line;
	int		fd;
	int		line_len;
	int		current_line_len;
	int 	line_count;

	line_count = 0;
	int countP = 0, countE = 0, countC = 0, count0 = 0, count1 = 0;
	line_len = 0;
	current_line_len = 0;
	
	fd = open(map, O_RDONLY);
	while (1)
	{
		size_t i;
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		i = 0;
		while (i < ft_strlen(line))
		{
				c = line[i];
				if (c == 'P')
					countP++;
				else if (c == 'E')
					countE++;
				else if (c == 'C')
					countC++;
				else if (c == '0')
					count0++;
				else if (c == '1')
					count1++;
				else if(c == '\n')
				{
					if(current_line_len > 0)
					{
						if(line_len == 0)
							line_len = current_line_len;
						//else if (current_line_len != line_len - 1)
						//	printf("Todas as linhas devem ter o mesmo tamanho\n");
					}
					current_line_len = 0;
				}
				else 
					printf("Caractere inválido encontrado: %c\n", c);

			i++;
		}
	
		current_line_len++;
		free(line);
	}

	if(line_len == 0)
		line_len = current_line_len;
	//else if(current_line_len != line_len)
	//{
	//	printf("Todas as linhas devem ter o mesmo tamanho\n");
	//	free(line);
	//}
	current_line_len = 0;
	line_count++;
	ft_split()
	if (countP == 1 && countE == 1 && countC >= 1 && count0 >= 1 && count1 >= 1 && line_count >= 3)
        init_mlx();
	else 
		printf("Erro\n");

	close(fd);
}

int32_t	main(int argc, char **argv)
{
	char *argument;
	argument = argv[1];
	if (argc == 2)
	{
		validate(argument);
	} else 
	{
		printf("Numero errado de argumentos");
	}

	return (EXIT_SUCCESS);
}