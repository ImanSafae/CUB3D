# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaouil <itaouil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 15:37:04 by abelhadi          #+#    #+#              #
#    Updated: 2022/11/21 17:17:27 by itaouil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	cub3d

FRAMEWORKS			=	-framework OpenGL -framework AppKit
CFLAGS				=	-Werror -Wextra -Wall -O2 -g -fsanitize=address
INCLUDES			=	-lmlx -IMLX -LMLX -I./includes/
LIB					=	libft/libft.a

SRCS_DIR			=	./srcs/
SRCS				=	main.c \

SRCS_DRAW_DIR			=	./srcs/draw/
SRCS_DRAW 				=	draw_3d.c \
							draw_utils.c \
							dda.c \
							key_hooks.c \
							ver_intersections.c \
							draw_3d_utils.c \
							movements.c \
							raycasting_utils.c \
							raycasting_utils2.c \
							colors.c \
							hor_intersections.c \
							
SRCS_BONUS_DIR			=	./srcs/bonus/
SRCS_BONUS				=	doors_bonus.c \
							draw_3d_bonus.c \
							fake_door_mode_bonus.c \
							key_hooks_bonus.c \
							main_bonus.c \
							mini_hooks_bonus.c \
							minimap_bonus.c \
							minimap2_bonus.c \
							parsing_bonus.c \
							parsing2_bonus.c \
							parsing_utils_bonus.c \
							rng_mode_bonus.c \
							textures_bonus.c \
							textures2_bonus.c \
							textures_parsing_bonus.c \

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
							free.c \
							textures_utils.c \
							textures_utils2.c \
							

								
SRCS_PATH			=	$(addprefix ${SRCS_DIR},${SRCS})
OBJS				=	$(addprefix ${SRCS_DIR},${SRCS:.c=.o})

SRCS_PARS_PATH		=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS})
PARS_OBJS			=	$(addprefix ${SRCS_PARS_DIR},${SRCS_PARS:.c=.o})

SRCS_DRAW_PATH		=	$(addprefix ${SRCS_DRAW_DIR},${SRCS_DRAW})
DRAW_OBJS			=	$(addprefix ${SRCS_DRAW_DIR},${SRCS_DRAW:.c=.o})

SRCS_BONUS_PATH		=	$(addprefix ${SRCS_BONUS_DIR},${SRCS_BONUS})
BONUS_OBJS			=	$(addprefix ${SRCS_BONUS_DIR},${SRCS_BONUS:.c=.o})


all:		${NAME}
			make all -C ./libft

${NAME}:	${OBJS} ${PARS_OBJS} ${DRAW_OBJS}
			gcc $(CFLAGS) ${LIB} ${SRCS_PATH} $(SRCS_PARS_PATH) $(SRCS_DRAW_PATH) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)



clean:
			make clean -C ./libft
			${RM} ${OBJS} ${PARS_OBJS} ${DRAW_OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			 fclean all

bonus:		fclean ${BONUS_OBJS} ${PARS_OBJS} ${DRAW_OBJS}
			@make all -C ./libft
			gcc $(CFLAGS) ${LIB} ${SRCS_BONUS_PATH} $(SRCS_PARS_PATH) $(SRCS_DRAW_PATH) $(INCLUDES) $(FRAMEWORKS) -o $(NAME)

.PHONY:		all clean fclean re bonus

push:
			git add .
			git status
			git commit -m cub3d
			git push

peach:		make bonus
			./cub3d peach_castle_bonus.cub

chrono:		make bonus
			./cub3d map_tig.cub