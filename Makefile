all: liblist.o
	gcc main.c -Wall liblist.o

liblist.o: liblist.c
	gcc -c liblist.c -Wall

clean:
	rm -f *.o a.out
