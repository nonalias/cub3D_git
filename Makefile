# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehkim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/07 14:44:57 by taehkim           #+#    #+#              #
#    Updated: 2020/09/17 21:18:13 by taehkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	cub3d

E_SRCS	=	./engine/cub3d.c \
			./engine/init.c \
			./engine/init2.c \
			./engine/callback.c \
			./engine/hookaction.c \
			./engine/move_w.c \
			./engine/move_s.c \
			./engine/move_a.c \
			./engine/move_d.c \
			./engine/wall.c \
			./engine/reset_player.c \
			./engine/sprite.c \
			./engine/raycasting_vert.c \
			./engine/raycasting_horz.c \
			./engine/utils.c \
			./engine/utils2.c \
			./engine/validation.c \
			./engine/validation2.c \
			./engine/pos.c \
			./engine/status.c \
			./engine/free.c \
			./engine/parse.c \
			./engine/option_parse.c \
			./engine/shading.c \
			./engine/bmp.c \

G_SRCS	=	./graphic/view.c \
			./graphic/make_2d.c \
			./graphic/make_3d.c \
			./graphic/make_rader.c \
			./graphic/make_ceil_floor.c \
			./graphic/make_rectangle.c \
			./graphic/make_crosshair.c \

GNLS	=	./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \

SRCS	=	$(G_SRCS)	\
			$(E_SRCS)	\
			$(GNLS)		\

OBJS	=	$(SRCS:.c=.o)

L_MLXS	=	./mlx

L_LIBFT	=	./libft

G_OPT	=	-lft -lmlx -framework OpenGL -framework Appkit

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L $(L_MLXS) -L $(L_LIBFT) $(G_OPT) 

%.o		:	%.c
	$(CC) $(CFLAGS) -I ./ -I ./get_next_line -o $@ -c $<

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
