NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = ./libft/libft.a
MLX = ./mlx

SRCS =	draw.c \
		init.c \
		main.c \
		moves.c \
		player.c \
		raycast.c \
		texture.c \
		utils.c \

SRC = $(addprefix ./srcs/,$(SRCS))
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT): 
	$(MAKE) -C ./libft

mlx_compiled:
	$(MAKE) -C $(MLX)

$(NAME): mlx_compiled $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C $(MLX)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re