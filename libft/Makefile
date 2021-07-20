# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjalo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 15:38:27 by tjalo             #+#    #+#              #
#    Updated: 2019/10/28 19:50:43 by tjalo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -Wall -Werror -Wextra
SRCS =	ft_atoi.c		\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strnstr.c		\
		ft_strdup.c			\
		ft_itoa.c			\
		ft_putchar_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_strmapi.c		\
		ft_strlcat.c		\
		ft_memcpy.c			\
		ft_substr.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memset.c			\
		ft_split.c			\
		ft_strchr.c			\
		ft_strjoin.c		\
		ft_strlcpy.c		\
		ft_strncmp.c		\
		ft_strrchr.c		\
		ft_strtrim.c		\
		ft_tolower.c		\
		ft_toupper.c

SRCS_BONUS =	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstnew.c			\
				ft_lstsize.c		\
				ft_lstmap.c

OBJS     = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
HEADERS  = ./includes
RM       = rm -f
NAME     = libft.a

all:	${NAME}


bonus:		${OBJS} ${OBJS_BONUS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

$(NAME):	${OBJS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

%.o:%.c
	${CC} -o $@ -c $<

clean    :
			${RM} ${OBJS} ${OBJS_BONUS}

fclean    : clean
			${RM} ${NAME}

re        : fclean all
