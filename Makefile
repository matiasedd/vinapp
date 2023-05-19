CC = gcc
CFLAGS = -Wall -g

all: liblist.o
	$(CC) main.c $(CFLAGS) liblist.o

liblist.o: liblist.c
	$(CC) -c liblist.c -Wall

clean:
	rm -f *.o a.out
