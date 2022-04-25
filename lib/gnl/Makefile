# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 16:44:44 by mhirabay          #+#    #+#              #
#    Updated: 2022/04/25 15:42:12 by wyohei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}

$(NAME) : $(OBJS)
CC = gcc 
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${OBJS}
re:	fclean all

.PHONY: all clean fclean re .c.o