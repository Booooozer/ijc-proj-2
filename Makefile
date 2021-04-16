CC=gcc
CFLAGS=-g -std=c99 -pedantic -fPIC -Wall -Wextra
exec=tail wordcount wordcount-dynamic
htab_dep=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o \
		htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o

all: $(exec)

#### TAIL
tail: tail.o
	$(CC) -g -std=c99 -pedantic -Wall -Wextra $^ -o $@

#### WORDCOUNT
wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) -o $@ -static wordcount.o io.o -L. -lhtab

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) -o $@ wordcount.o io.o -L. -lhtab

# Static library
libhtab.a: $(htab_dep)
	ar rcs $@ $^

# Dynamic library
libhtab.so: $(htab_dep)
	$(CC) $(CFLAGS) -shared -o $@ $^


#### Object files
tail.o: tail.c
	$(CC) -g -std=c99 -pedantic -Wall -Wextra -c $^

wordcount.o: wordcount.c
	$(CC) -g -std=c99 -pedantic -Wall -Wextra -c $<

io.o: io.c io.h
	$(CC) -g -std=c99 -pedantic -Wall -Wextra -c $<

# libhtab objects
%.o: %.c
	$(CC) $(CFLAGS) -c $^

#### MISC
run: $(exec)
	#./wordcount proj2Notes
	LD_LIBRARY_PATH="." ./wordcount-dynamic proj2Notes

clean:
	rm -f *.o $(exec) libhtab.a libhtab.so
