# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/04/30 08:28:55 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= cub3D
SRCDIR 	:= ./src/
SRCNAME	:=	main.c \
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
			

SRCS	:= $(addprefix $(SRCDIR), $(SRCNAME))
OBJSDIR	:= ./obj/
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCNAME:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra #-g -fsanitize=address
INC		:= -I ./includes
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

.PHONY: all clean fclean re
