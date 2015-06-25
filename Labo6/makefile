CC = gcc
OPTIONS = -Wall
EXE = main

all: link

compile: main.o inventaire.o

main.o: main.c inventaire.h
	$(CC) $(OPTIONS) -c main.c

inventaire.o: inventaire.c inventaire.h
	$(CC) $(OPTIONS) -c inventaire.c

link: compile
	$(CC) *.o -o $(EXE)

clean:
	rm $(EXE)
	rm *.o

start: link
	./$(EXE)
