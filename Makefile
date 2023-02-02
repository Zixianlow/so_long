# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 11:17:50 by lzi-xian          #+#    #+#              #
#    Updated: 2023/01/18 14:23:58 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SL_NAME		=	so_long
SRCS		=	ft_enemy_move.c				\
				ft_enemy_position.c			\
				ft_file_name_check.c		\
				ft_get_image.c				\
				ft_get_map.c				\
				ft_movement.c				\
				ft_put_moves_count.c		\
				ft_render_map.c				\
				ft_sl_free_n_exit.c			\
				ft_slgamestate.c			\
				ft_valid.c					\
				so_long.c					\
				get_next_line/get_next_line.c	\
				get_next_line/get_next_line_utils.c
LIBFT		=	libft/libft.a
OBJS		=	${SRCS:.c=.o}
NAME		=	so_long.a
ARCR		= 	ar cr
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
GCC			=	gcc

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	touch $(NAME)
	cp ${LIBFT} .
	mv libft.a $(NAME)
	${ARCR} ${NAME} ${OBJS}
	make run

run:
	${GCC} ${CFLAGS} -lmlx -framework OpenGL -framework AppKit -lz $(NAME) -o ${SL_NAME}

all:	$(NAME)

clean:
	${RMRF} ${OBJS}

fclean:	clean
	${RMRF} $(NAME) ${SL_NAME} bonus

bonus:	$(NAME)

re:	fclean all