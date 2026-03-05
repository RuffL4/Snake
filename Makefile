CC = gcc
CFLAGS = -Wall
LIBS = -lraylib


snake: main.c rendering.c
	$(CC) main.c rendering.c $(CFLAGS) $(LIBS) -o snake

clean:
	rm -f snake
