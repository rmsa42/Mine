# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 10:56:36 by rumachad          #+#    #+#              #
#    Updated: 2023/07/04 16:19:47 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRC = push_swap.c movements.c movements2.c \
		movements3.c ps_list_utils.c ps_sort_utils.c \
		ps_sort_five.c ps_sort_big.c ps_strat.c \
		ps_sort_three.c ps_strat2.c ps_errors.c \
		ps_sort_big2.c ps_sort_big3.c
LIBFT_DIR = libft
MAKE = make
OBJS = ${SRC:.c=.o}
HEADER = push_swap.h
INCLUDE = -I include
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
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
		${MAKE} -C ${LIBFT_DIR} fclean
		${RM} ${NAME}

re:	fclean ${NAME}

.SILENT:
