CC = gcc
CFLAGS = -Wall
LIBS = -lraylib


snake: main.c rendering.c logic.c
	$(CC) main.c rendering.c logic.c $(CFLAGS) $(LIBS) -o snake

clean:
	rm -f snake
