# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjalo <tjalo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 15:00:02 by tjalo             #+#    #+#              #
#    Updated: 2021/07/23 06:27:30 by tjalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./include

LDFLAGS = -L ./mlx

HEADER = -I ./include -I mlx

LIB = -lm -lmlx -lXext -lX11

LIBFTSRC =	libft/ft_split.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/get_next_line.c \
		libft/ft_putchar.c \
		libft/ft_putnbr.c \
		libft/ft_isdigit.c \
		libft/ft_putstr_fd.c \
		libft/ft_strchr.c \
		libft/ft_isascii.c \
		libft/ft_strtrim.c \
		libft/ft_strncmp.c \
		libft/ft_bzero.c

SRC =	srcs/parse_map.c \
		srcs/parse.c \
		srcs/map.c \
		srcs/display.c \
		srcs/error.c \
		srcs/init.c \
		srcs/handle_event.c \
		srcs/position.c \
		srcs/utils.c \
		srcs/draw.c \
		srcs/main.c \
		${LIBFTSRC}

OBJ = ${SRC:.c=.o}

all:	${NAME}

$(NAME):	${OBJ}
			make -C mlx/
			$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) $(LIB)

%.o%.c:
	${CC} -c ${CFLAGS} -I ${HEADER} -I/usr/include -lmlx -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJ}
	make clean -C mlx

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
