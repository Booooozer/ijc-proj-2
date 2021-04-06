CC=gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra
EXEC="tail"

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm *.o $(EXEC)
