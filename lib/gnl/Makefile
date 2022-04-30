# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 16:44:44 by mhirabay          #+#    #+#              #
#    Updated: 2022/04/30 09:28:13 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRCS = get_next_line.c get_next_line_utils.c util.c
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