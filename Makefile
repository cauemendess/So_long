NAME = so_long
INCLUDE = -I ./src/ -I $(LIBMLX)/include/MLX42

CFLAGS = -Wall -Werror -Wextra -g3

MLX = ./MLX42/build/libmlx42.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft/

LIBMLX = ./MLX42
OBJ_DIR = ./obj
MLXFLAGS = $(MLX) $(INCLUDE) -ldl -lglfw -pthread -lm


SOURCES = $(addprefix src/, so_long.c initialize_game.c validate.c \
error_and_free.c check_path.c place.c render.c move.c delete_images.c move_bonus.c my_enemy_bonus.c)

OBJECTS = $(SOURCES:%.c=%.o)

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./src/so_long.h

$(LIBFT):
	make -C ./libft

$(MLX):
	cmake -S ./MLX42 -B ./MLX42/build -DDEBUG=1
	cmake --build ./MLX42/build -j4

libclean:
	@make clean -C ./libft --no-print-directory

libfclean: libclean
	@make fclean -C ./libft --no-print-directory

clean: libclean
	@rm -rf $(OBJECTS)

fclean: clean libfclean
	@cd ./MLX42/build && make clean --no-print-directory
	@rm -f $(NAME)

re: fclean all

bonus: all

mlxre:
	cmake --build ./MLX42/build --clean-first --no-print-directory

reall: fclean mlxre all

.PHONY: all clean fclean re mlxre reall libfclean libclean libft