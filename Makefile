SRCS	=	./cub3d.c \
			./init.c \
			./init2.c \
			./callback.c \
			./hookaction.c \
			./move_w.c \
			./move_s.c \
			./move_a.c \
			./move_d.c \
			./wall.c \
			./view.c \
			./make_2d.c \
			./make_3d.c \
			./make_rader.c \
			./make_player.c \
			./raycasting_vert.c \
			./raycasting_horz.c \
			./make_ceil.c \
			./make_floor.c \
			./utils.c \


all:
	gcc -L ./mlx -L ./libft -lft -lmlx -framework OpenGL -framework Appkit $(SRCS) -I ./
	./a.out abc.cub --save --debug

# save랑 debug 딱 맞는지 체크해줘야함. (debugs 같은것도 debug로 인식)
