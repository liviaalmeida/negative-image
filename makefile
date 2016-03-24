all: negimg

negimg: main.o pgm.o
	gcc -o negimg main.o pgm.o

main.o: main.c
	gcc -c main.c

pgm.o: pgm.c
	gcc -c pgm.c

clean:
	rm -rf *o hello
