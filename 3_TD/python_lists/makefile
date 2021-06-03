main: main.o list.o
	gcc -o main main.o list.o

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h
	gcc -c main.c

clean:
	rm -f *.o

run:
	./main

