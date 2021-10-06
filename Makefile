NAME		:= cub3D
HDRS		:= cub3d.h

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRCS_DIR	:= sources
HDRS_DIR	:= headers
vpath %.c	$(SRCS_DIR)
vpath %.h	$(HDRS_DIR)

INCLUDES	:= -I$(HDRS_DIR)
MLX			:= mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a
LIBS		:= -L/usr/include/../lib -lXext -lX11 -lm -lbsd

SRCS		:= add_funcs_2.c \
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


OBJS_DIR	:= .objects
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all:
					@echo "$(BOLD)Creating/updating '$(NAME)':$(DEF)"
					@$(MAKE) --no-print-directory $(NAME)

$(NAME):			$(OBJS)
					@echo "$(BOLD)Linking files...$(DEF)"
					@$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(MLX) $(LIBS) -o $@
					@echo "$(BOLD)'$(NAME)' has been created/updated.$(DEF)"

$(OBJS_DIR)/%.o:	%.c $(HDRS) | $(OBJS_DIR)
					@echo "Assembling $<..."
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@
					@echo "$(BOLD)Directory '$(OBJS_DIR)' has been created.$(DEF)"

clean:
					@rm -rf $(OBJS)
					@echo "$(NAME): $(BOLD)Object files have been cleaned.$(DEF)"

fclean:				clean
					@rm -rf $(NAME)
					@echo "$(BOLD)'$(NAME)' has been cleaned.$(DEF)"

re:					fclean all

.PHONY:				all clean fclean re

BOLD	:= \033[1m
DEF		:= \033[0;39m