.PHONY: betty

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

main: main.c heap.c heap.h
	$(CC) -o main $(CFLAGS) main.c heap.c && ./main

betty:
	betty main.c heap.c heap.h
