CC = gcc
OPTIONS = -Wall
EXE = Fichiers
OBJS = entreeSortie.o manipulationFichiers.o main.o

.SUFFIXES: .c .o

all: link

compile: $(OBJS)

.c.o:
	$(CC) $(OPTIONS) -c $*.c

link: compile
	$(CC) $(OBJS) -o $(EXE)

clean:
	rm $(EXE)
	rm $(OBJS)

start: link
	./$(EXE)
