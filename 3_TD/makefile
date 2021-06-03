.PHONY: all clean

all: main

main: main.o personne.o date.o list.o
	@echo "Linking everyting..."
	gcc -o main main.o personne.o date.o list.o 

list.o: list.c list.h date.h
	@echo "Building list dependency..."
	gcc -c list.c

date.o: date.c date.h
	@echo "Building date dependency..."
	gcc -c date.c

personne.o: personne.c personne.h
	@echo "Building person dependency..."
	gcc -c personne.c

run:
	./main

clean:
	@echo "Cleaning everything..."
	rm -f *.o
