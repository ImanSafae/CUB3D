# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:53:03 by abelhadi          #+#    #+#              #
#    Updated: 2022/08/16 18:48:10 by abelhadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a 
CC			=	gcc 
SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_split_c.c \
				list_functions.c \
				list_functions2.c \
				list_functions3.c \

SRC_BONUS 	= 	list_functions.c \
				list_functions2.c \
				list_functions3.c \

CFLAGS		=	-Wall -Wextra -Werror -g
OBJS		=	${SRCS:.c=.o}
BON_OBJS	=	${SRC_BONUS:.c=.o}
HEADERS		=	libft.h
RM			=	rm -f

.o:.c
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADERS}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:		$(OBJS) $(BON_OBJS)
			ar rcs $(NAME) $(OBJS) $(BON_OBJS)		

clean:
			${RM} ${OBJS} ${BON_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
