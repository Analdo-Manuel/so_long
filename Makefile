NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = 	sources/so_long.c 				\
			sources/map_handler.c 			\
			sources/memory_free.c 			\
			sources/route_verification.c	\
			sources/v_componentes.c 		\
			sources/events.c 				\
			sources/utils.c
OBJ = ${SOURCE:.c=.o}
MLX_DIR = minilibx-linux

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

clean:
	@make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
