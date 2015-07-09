CC = gcc
OPTIONS = -Wall
EXE = main

all: link

compile: main.o chaine.o produit.o pileProduit.o

main.o: main.c chaine.h produit.h
	$(CC) $(OPTIONS) -c main.c
	
pileProduit.o: pileProduit.c pileProduit.h produit.h
	$(CC) $(OPTIONS) -c pileProduit.c
	
produit.o: produit.c produit.h
	$(CC) $(OPTIONS) -c produit.c

chaine.o: chaine.c chaine.h
	$(CC) $(OPTIONS) -c chaine.c

link: compile
	$(CC) *.o -o $(EXE)

clean:
	rm $(EXE)
	rm *.o

start: link
	./$(EXE)