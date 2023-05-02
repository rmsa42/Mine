# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 12:39:58 by rumachad          #+#    #+#              #
#    Updated: 2023/05/02 12:16:54 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_itoa.c ft_printhexa.c \
		ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_printhexa_upp.c ft_put_unsi_nbr.c \
		ft_printpointer.c
OBJS = ${SRC:.c=.o}
HEADER = ft_printf.h
INCLUDE = -I include
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS} ${HEADER}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean ${NAME}

.PHONY:	all	clean fclean re