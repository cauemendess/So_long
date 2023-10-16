#include "so_long.h"

void	validate_map(t_game *game)
{
	char	c;
	char	*line;

	int		line_len;
	int		current_line_len;
	int 	line_count;

	line_count = 0;
	line_len = 0;
	current_line_len = 0;

	while (1)
	{
		size_t i;
		line = get_next_line(game->fd);

		if (!line)
			break;
		i = 0;
		while (i < ft_strlen(line))
		{
				c = line[i];
				if (c == 'P')
					game->map.player++;
				else if (c == 'E')
					game->map.exits++;
				else if (c == 'C')
					game->map.coin++;
				else if (c == '0')
					game->map.floor++;
				else if (c == '1')
					game->map.walls++;

				// fazer uma função para pular \n e \0 pra fazer essa parte
				if(c == '\n')
				{
					if(current_line_len > 0)
					{
						if(line_len == 0)
							line_len = current_line_len;
						else if (current_line_len != line_len - 1)
							printf("Todas as linhas devem ter o mesmo tamanho\n");
					}
					current_line_len = 0;
				}
				else 
					printf("Caractere inválido encontrado: %c\n", c);

			i++;
		}
		printf("%s\n", line);
	
		current_line_len++;
		free(line);
	}

	if(line_len == 0)
		line_len = current_line_len;
	else if(current_line_len != line_len)
	{
		printf("Todas as linhas devem ter o mesmo tamanho\n");
		free(line);
	}
	line_count = current_line_len;
	printf("%d\n", line_count);
	if (game->map.player == 1 && game->map.exits == 1 && game->map.coin >= 1 && game->map.floor >= 1 && game->map.walls >= 1 && line_count >= 3)
        init_mlx();
	else 
		printf("Erro\n");

	close(game->fd);
}