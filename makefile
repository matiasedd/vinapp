CC = gcc
CFLAGS = -Wall -g
TARGET = vina++

all: liblist.o
	$(CC) main.c $(CFLAGS) liblist.o -o $(TARGET)

liblist.o: liblist.c liblist.h
	$(CC) -c liblist.c $(CFLAGS)

clean:
	rm -f *.o $(TARGET)
