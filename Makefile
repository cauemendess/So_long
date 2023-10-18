NAME = so_long
INCLUDE = -I ./src/ -I $(LIBMLX)/include/MLX42

CFLAGS = -Wall -Werror -Wextra -g3

MLX = ./MLX42/build/libmlx42.a 	
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

LIBMLX = ./MLX42
OBJ_DIR = ./obj
MLXFLAGS = $(MLX) $(INCLUDE) -ldl -lglfw -pthread -lm


# colors
GREEN = \033[1;32m
RED = \033[1;31m
RESET = \033[0m

SOURCES = $(addprefix src/, so_long.c initialize_game.c validate.c error.c)

OBJECTS = $(SOURCES:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJECTS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./src/so_long.h

$(LIBFT):
	make -C ./libft

$(MLX):
	cmake -S ./MLX42 -B ./MLX42/build -DDEBUG=1
	cmake --build ./MLX42/build -j4

clean: 
	@rm -rf $(OBJECTS)


fclean: clean libfclean
	@rm -f $(NAME)


libclean:
	@make clean -C ./libft --no-print-directory

libfclean:
	@make fclean -C ./libft --no-print-directory


re: fclean all

mlxre:
	cmake --build ./MLX42/build --clean-first --no-print-directory

reall: fclean mlxre all

.PHONY: all clean fclean re mlxre reall