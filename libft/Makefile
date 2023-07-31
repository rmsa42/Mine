# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 15:31:41 by rumachad          #+#    #+#              #
#    Updated: 2023/05/03 10:41:22 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c \
		ft_isprint.c ft_isascii.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_atoi.c \
		ft_strncmp.c ft_memcpy.c ft_memchr.c \
		ft_memmove.c ft_strnstr.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_itoa.c ft_memcmp.c \
		ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_split.c
OBJS = ${SRC:.c=.o}
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = ${BONUS_SRC:.c=.o}
HEADER = libft.h
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
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${RM} ${NAME}

re:	fclean ${NAME}

bonus:	${BONUS_OBJS}
			ar rcs ${NAME} ${BONUS_OBJS}

.PHONY:	all	clean fclean re bonus

