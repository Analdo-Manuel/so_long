NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = so_long.c map_handler.c memory_free.c route_verification.c v_componentes.c
OBJ = ${SOURCE:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all