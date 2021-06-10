all: main

main.o: main.c
	gcc -c main.c

elevator.o: elevator.c
	gcc -c elevator.c

person.o: person.c
	gcc -c person.c

main: person.o elevator.o main.o
	gcc -o main main.o person.o elevator.o -lncurses

debug:	person.o elevator.o main.o
	gcc -o main-debug main.o person.o elevator.o -lncurses

clean:
	rm *.o
