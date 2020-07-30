SRCS	=	./cub3d.c \
			./init.c \

all:
	gcc -L ./mlx -lmlx -framework OpenGL -framework Appkit $(SRCS) -I ./
	./a.out
