CC = gcc
CFLAGS = -Wall

TARGET = vina++
OBJETCS = liblist.o libfile.o libvina.o

all: $(OBJETCS)
	$(CC) main.c -o $(TARGET) $(CFLAGS) $(OBJETCS)

liblist.o: liblist.c
	$(CC) -c liblist.c

libfile.o: libfile.c
	$(CC) -c libfile.c

libvina.o: libvina.c
	$(CC) -c libvina.c

clean:
	rm -f *.o $(TARGET)
