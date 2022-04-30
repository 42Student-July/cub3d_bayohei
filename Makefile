# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/04/30 09:36:02 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= cub3D
SRCDIR 	:= ./src/
SRC_BONUS_DIR 	:= ./src_bonus/
SRCNAME :=	main.c \
			move.c \
			move_direction.c \
			ray.c \
			ray_utils.c \
			cub_utils.c \
			debug.c \
			render_3d.c \
			render_3d_utils.c \
			render_3d_utils_2.c \
			render_minimap.c \
			render_utils.c \
			render_rays.c \
			error_handling.c \
			init.c \
			init_2.c \
			hooks.c \
			look.c \
			arg_check.c \
			error_util.c \
			parser.c \
			pars_util.c \
			pars_util2.c \
			load_texture.c \
			pars_color.c \
			libft_util.c \
			check_elements.c \
			map_check.c \
			dfs_map.c\
			get_map.c \
			ray_utils_2.c \
			init_3.c \
			move_utils.c

SRC_NAME_BONUS	:=	main_bonus.c \
			move_bonus.c \
			move_direction_bonus.c \
			ray_bonus.c \
			ray_utils_bonus.c \
			cub_utils_bonus.c \
			debug_bonus.c \
			render_3d_bonus.c \
			render_3d_utils_bonus.c \
			render_3d_utils_2_bonus.c \
			render_minimap_bonus.c \
			render_utils_bonus.c \
			render_rays_bonus.c \
			error_handling_bonus.c \
			init_bonus.c \
			init_2_bonus.c \
			hooks_bonus.c \
			look_bonus.c \
			arg_check_bonus.c \
			error_util_bonus.c \
			parser_bonus.c \
			pars_util_bonus.c \
			pars_util2_bonus.c \
			load_texture_bonus.c \
			pars_color_bonus.c \
			libft_util_bonus.c \
			check_elements_bonus.c \
			map_check_bonus.c \
			dfs_map_bonus.c\
			get_map_bonus.c \
			ray_utils_2_bonus.c \
			init_3_bonus.c \
			move_utils_bonus.c


SRCS	:= $(addprefix $(SRCDIR), $(SRCNAME))
OBJSDIR	:= ./obj/
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCNAME:%.c=%.o))

SRCS_BONUS	:= $(addprefix $(SRC_BONUS_DIR), $(SRC_NAME_BONUS))
OBJS_BONUS 	:= $(addprefix $(OBJSDIR), $(SRC_NAME_BONUS:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra
INC		:= -I ./includes
INC_BONUS := -I ./includes_bonus
RM		:= rm -rf
DEBUG	:= -g -fsanitize=address
LDFLAGS := -Llib/gnl -Llib/libft
LIBS 	:= -lgnl -lft
MLX_NAME = lib/mlx
MLXD = ./$(MLX_NAME)
MLX = $(MLXD)/libmlx.a
UNAME := $(shell uname)

ifeq (${UNAME},Darwin)
	OPT_MLX = -I/usr/X11/include -Llib/mlx -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11 -lm
else
	OPT_MLX = -L$(MLX_NAME) -lmlx  -I$(MLX_NAME) -lXext -lX11 -lm
endif

ifdef WITH_BONUS
	OBJS = $(OBJS_BONUS)
endif

all: lib ${NAME}

lib : dummy
	make -C lib/gnl
	make -C lib/mlx
	make -C lib/libft

.PHONY: dummy

dummy:

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS)  $(INC) $^ ${LDFLAGS} ${LIBS} $(OPT_MLX)  -o $@

$(OBJSDIR)%.o : $(SRCDIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	${CC} ${CFLAGS} $(INC) -c $< -o $@
bonus: lib
	make WITH_BONUS=1

$(OBJSDIR)%.o : $(SRC_BONUS_DIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	${CC} ${CFLAGS} $(INC) -c $< -o $@

clean:
	make clean -C lib/gnl
	make clean -C lib/libft
	make clean -C lib/mlx
	$(RM) $(OBJSDIR)

fclean: clean
	make fclean -C lib/gnl
	make fclean -C lib/libft
	make clean -C lib/mlx
	${RM} lib/mlx/libmlx_Linux.a
	${RM} ${NAME} 
re:	fclean all

.PHONY: all clean fclean re bonus
