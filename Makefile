CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -O2

run: main
	./main

all: main

main: main.o src/quicksort.o
	$(CC) -o main main.o src/quicksort.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

src/quicksort.o: src/quicksort.c
	$(CC) $(CFLAGS) -o src/quicksort.o 	-c src/quicksort.c

clean:
	rm -f *.o main src/*.o
