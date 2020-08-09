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
			./graphic/view.c \
			./graphic/make_2d.c \
			./graphic/make_3d.c \
			./graphic/make_rader.c \
			./graphic/make_player.c \
			./engine/raycasting_vert.c \
			./engine/raycasting_horz.c \
			./engine/utils.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./pos.c \

all:
	gcc -L ./mlx -L ./libft -lft -lmlx -framework OpenGL -framework Appkit $(SRCS) -I ./ -I ./get_next_line
	./a.out abc.cub --save --debug

# save랑 debug 딱 맞는지 체크해줘야함. (debugs 같은것도 debug로 인식)
