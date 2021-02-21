.PHONY: build
CFLAGS=-Wall -Wextra -ggdb -pedantic
INCLUDE=-I include/
LIBS=-L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

build: main.c
	$(CC) $(CFLAGS) -o monlo main.c $(INCLUDE) $(LIBS) 