# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/04/18 17:18:02 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= cub3D
SRCDIR 	:= ./src/
SRCNAME	:=	main.c \
			move.c \
			ray.c \
			cub_utils.c \
			debug.c \
			render_3d.c \
			render_minimap.c \
			render_utils.c \
			render_rays.c \
			error_handling.c \
			init.c \
			init_2.c \
			args_handling.c \
			hooks.c \
			look.c \

SRCS	:= $(addprefix $(SRCDIR), $(SRCNAME))
OBJSDIR	:= ./obj/
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCNAME:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra
INC		:= -I ./includes
RM		:= rm -rf
DEBUG	:= -g -fsanitize=address
LDFLAGS := -Llib/gnl -Llib/libft
LIBS 	:= -lgnl -lft

UNAME := $(shell uname)

ifeq (${UNAME},Darwin)
	OPT_MLX = -I/usr/X11/include -Llib/mlx -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11 -lm
else
	OPT_MLX = -Ilib/mlx -Llib/mlx -lmlx -lXext -lX11 -lm
endif

all: lib ${NAME}

lib : dummy
	make -C lib/gnl
	make -C lib/mlx
	make -C lib/libft

.PHONY: dummy

dummy:

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC)  ${LDFLAGS} ${LIBS} $(OPT_MLX) $^ -o $@

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

.PHONY: debug
debug:	CFLAGS += $(DEBUG)
debug:	re

.PHONY: all clean fclean re
