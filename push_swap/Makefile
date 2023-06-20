# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:56:36 by rumachad          #+#    #+#              #
#    Updated: 2023/06/20 17:00:41 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRC = push_swap.c movements.c movements2.c \
		movements3.c ps_list_utils.c ps_sort_utils.c
LIBFT_DIR = libft
LIBFT_OBJS = 
MAKE = make -C
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
			${MAKE} ${LIBFT_DIR}

all:	${NAME}

clean:
		${MAKE} ${LIBFT_DIR} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_DIR} fclean
		${RM} ${NAME}

re:	fclean ${NAME}
