# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 15:37:04 by abelhadi          #+#    #+#              #
#    Updated: 2022/09/02 16:57:13 by itaouil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3d

FRAMEWORKS			=	-framework OpenGL -framework AppKit
FLAGS				=	-Werror -Wextra -Wall -g -fsanitize=address
INCLUDES			=	-lmlx -I./includes/
LIB					=	libft/libft.a

SRCS_DIR			=	./srcs/
SRCS				=	main_cub.c \

SRCS_DRAW_DIR			=	./srcs/draw/
SRCS_DRAW 				=	draw_map.c \
							draw_utils.c \
							# draw_rays.c \

SRCS_PARS_DIR			=	./srcs/parsing/
SRCS_PARS				=	get_next_line.c \
							get_next_line_utils.c \
							parsing.c \
							parsing_utils.c \
							parsing_utils2.c \
							map_utils.c \
							color_utils.c \
							clean_map_utils.c \
							utils.c \
							utils2.c \
							textures_utils.c \
							textures_utils2.c \
							

								
SRCS_PATH			=	$(addprefix ${SRCS_DIR},${SRCS})
OBJS				=	$(addprefix ${SRCS_DIR},${SRCS:.c=.o})

SRCS_PARS_PATH		=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS})
PARS_OBJS			=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS:.c=.o})

SRCS_DRAW_PATH		=	$(addprefix ${SRCS_DRAW_DIR},${SRCS_DRAW})
DRAW_OBJS			=	$(addprefix ${SRCS_DRAW_DIR},${SRCS_DRAW:.c=.o})


all:		${NAME}
			make all -C ./libft

${NAME}:	${OBJS} ${PARS_OBJS} ${DRAW_OBJS}
			gcc $(FLAGS) ${LIB} ${SRCS_PATH} $(SRCS_PARS_PATH) $(SRCS_DRAW_PATH) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)



clean:
			make clean -C ./libft
			${RM} ${OBJS} ${PARS_OBJS} ${DRAW_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			 fclean all

push:
			git add .
			git status
			git commit -m cub3d
			git push