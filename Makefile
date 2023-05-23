CC = gcc
CFLAGS = -Wall

OBJETCS = liblist.o libfile.o libvina.o

all: $(OBJETCS)
	$(CC) main.c $(CFLAGS) $(OBJETCS)

liblist.o: liblist.c
	$(CC) -c liblist.c

libfile.o: libfile.c
	$(CC) -c libfile.c

libvina.o: libvina.c
	$(CC) -c libvina.c

clean:
	rm -f *.o a.out
