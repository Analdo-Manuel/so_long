NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = so_long.c map_handler.c memory_free.c route_verification.c v_componentes.c events.c
OBJ = ${SOURCE:.c=.o}

# Diretório do subdiretório onde está o Makefile
MLX_DIR = minilibx-linux

# Regras principais
all: $(NAME)

# Regra para construir o projeto principal
$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

# Regra para limpar arquivos objeto
clean:
	@make clean -C $(MLX_DIR)
	rm -f $(OBJ)

# Regra para limpar tudo, incluindo o binário
fclean: clean
	rm -f $(NAME)

# Regra para limpar e reconstruir
re: fclean all
