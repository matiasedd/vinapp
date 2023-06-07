CC = gcc
CFLAGS = -Wall -g
TARGET = vina++

all: liblist.o libvina.o
	$(CC) main.c $(CFLAGS) liblist.o libvina.o -o $(TARGET)

liblist.o: liblist.c liblist.h
	$(CC) -c liblist.c $(CFLAGS)

libvina.o: libvina.c libvina.h liblist.h
	$(CC) -c libvina.c $(CFLAGS)

clean:
	rm -f *.o $(TARGET)
