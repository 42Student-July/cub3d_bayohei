# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/03/30 16:42:25 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= cub3D
SRCDIR 	:= ./src/
SRCNAME	:=	main.c \
			move.c \
			vision.c \
			cub_utils.c \

SRCS	:= $(addprefix $(SRCDIR), $(SRCNAME))
OBJSDIR	:= ./obj/
OBJS 	:= $(addprefix $(OBJSDIR), $(SRCNAME:%.c=%.o))

CC		:= gcc 
CFLAGS	:= -Wall -Werror -Wextra
INC		:= -I ./includes
RM		:= rm -rf
DEBUG	:= -g -fsanitize=address


UNAME := $(shell uname)

ifeq (${UNAME},Darwin)
	OPT_MLX = -I/usr/X11/include -Llib/mlx -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11 -lm
else
	OPT_MLX = -Ilib/mlx -Llib/mlx -lmlx -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OPT_MLX) $^ -o $@

$(OBJSDIR)%.o : $(SRCDIR)%.c
	@if [ ! -d $(OBJSDIR) ]; then mkdir $(OBJSDIR); fi
	${CC} ${CFLAGS} $(INC) -c $< -o $@

clean: 
	$(RM) $(OBJSDIR)

fclean: clean
	${RM} ${NAME} 
re:	fclean all

.PHONY: debug
debug:	CFLAGS += $(DEBUG)
debug:	re

.PHONY: all clean fclean re
