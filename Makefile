all:
	gcc -L ../mlx -lmlx -framework OpenGL -framework Appkit main.c
	./a.out
