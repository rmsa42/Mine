# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:56:36 by rumachad          #+#    #+#              #
#    Updated: 2023/06/21 14:04:19 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRC = push_swap.c movements.c movements2.c \
		movements3.c ps_list_utils.c ps_sort_utils.c
LIBFT_DIR = libft
LIBFT_OBJS = 
MAKE = make
OBJS = ${SRC:.c=.o}
HEADER = push_swap.h
INCLUDE = -I include
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS} ${HEADER}
			${MAKE} -C ${LIBFT_DIR}

all:	${NAME}

clean:
		${MAKE} -C ${LIBFT_DIR} clean
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean ${NAME}
