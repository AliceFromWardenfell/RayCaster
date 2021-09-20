NAME = cub3D

MLX = mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a
LIBRARIES = -L/usr/include/../lib -lXext -lX11 -lm -lbsd

BMP	= first_rendered_image.bmp
CC = gcc
FLAGS = -g -Wall -Werror -Wextra

SRC =	add_funcs_2.c \
		add_funcs_3.c \
		add_funcs.c \
		bmp.c \
		check_args_and_init.c \
		dda_h.c \
		dda_v.c \
		draw_3d_view.c \
		ft_split.c \
		ft_strtrim.c \
		gnl_analog.c \
		item_loop.c \
		load_images.c \
		main_2.c \
		main.c \
		map_check.c \
		map_parser.c \
		move_add_funcs_2.c \
		move_add_funcs.c \
		move_check_diag.c \
		move_wasd.c \
		parser.c \
		pixel_funcs.c \
		set_identificators_2.c \
		set_identificators.c \
		shortest_ray.c \

OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(FLAGS) -o ${NAME} ${OBJ} ${MLX} ${LIBRARIES}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(BMP)

re: fclean all

.PHONY: re all clean fclean