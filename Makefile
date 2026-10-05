main: main.c heap.c heap.h
	gcc -o main -Wall -Werror -Wextra -pedantic main.c heap.c && ./main
