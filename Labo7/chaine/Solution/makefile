CC = gcc
OPTIONS = -Wall
EXE = main

all: link

compile: main.o chaine.o

main.o: main.c chaine.h
	$(CC) $(OPTIONS) -c main.c

chaine.o: chaine.c chaine.h
	$(CC) $(OPTIONS) -c chaine.c

link: compile
	$(CC) *.o -o $(EXE)

clean:
	rm $(EXE)
	rm *.o

start: link
	./$(EXE)