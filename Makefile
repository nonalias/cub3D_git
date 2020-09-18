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

SRCS	=	./cub3d.c \
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
			./graphic/view.c \
			./graphic/make_2d.c \
			./graphic/make_3d.c \
			./graphic/make_rader.c \
			./graphic/make_ceil_floor.c \
			./graphic/make_rectangle.c \
			./graphic/make_crosshair.c \
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
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./bmp.c \

all:
	gcc -g3 -fsanitize=address -L ./mlx -L ./libft -lft -lmlx -framework OpenGL -framework Appkit $(SRCS) -I ./ -I ./get_next_line
	./a.out abc.cub --save --debug

# save랑 debug 딱 맞는지 체크해줘야함. (debugs 같은것도 debug로 인식)
