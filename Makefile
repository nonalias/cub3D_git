SRCS	=	./cub3d.c \
			./init.c \
			./callback.c \
			./hookaction.c \
			./move_w.c \
			./move_s.c \
			./move_a.c \
			./move_d.c \
			./wall.c \
			./view.c \
			./make_2d.c \
			./make_rader.c \


all:
	gcc -L ./mlx -lmlx -framework OpenGL -framework Appkit $(SRCS) -I ./
	./a.out
