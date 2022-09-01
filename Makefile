# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelhadi <abelhadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 15:37:04 by abelhadi          #+#    #+#              #
#    Updated: 2022/09/01 14:17:39 by abelhadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3d

FRAMEWORKS			=	-framework OpenGL -framework AppKit
FLAGS				=	-Werror -Wextra -Wall -g -fsanitize=address
INCLUDES			=	-lmlx -I./includes/
LIB					=	libft/libft.a

SRCS_DIR			=	./srcs/
SRCS				=	main_cub.c draw_map.c \

SRCS_PARS_DIR			=	./srcs/parsing/
SRCS_PARS				=	get_next_line.c \
							get_next_line_utils.c \
							parsing.c \
							parsing_utils.c \
							parsing_utils2.c \
							map_utils.c \
							textures_utils.c \
							textures_utils2.c \
							color_utils.c \
							clean_map_utils.c \
							utils.c \
							utils2.c \
							

								
SRCS_PATH			=	$(addprefix ${SRCS_DIR},${SRCS})
OBJS				=	$(addprefix ${SRCS_DIR},${SRCS:.c=.o})

SRCS_PARS_PATH		=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS})
PARS_OBJS			=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS:.c=.o})


all:		${NAME}
			make all -C ./libft

${NAME}:	${OBJS} ${PARS_OBJS}
			gcc $(FLAGS) ${LIB} ${SRCS_PATH} $(SRCS_PARS_PATH) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)



clean:
			make clean -C ./libft
			${RM} ${OBJS} ${PARS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			 fclean all

push:
			git add .
			git status
			git commit -m cub3d
			git push