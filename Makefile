CC=gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra
EXEC="tail"

tail: tail.o
	$(CC) $(CFLAGS) $^ -o $@

tail.o: tail.c
	$(CC) $(CFLAGS) -c $^ -o $@

wordcount: wordcount.c io.c htab*
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o $(EXEC)
