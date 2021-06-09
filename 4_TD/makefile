all: main

person.o: person.c
	gcc -c person.c

date.o: date.c
	gcc -c date.c

list.o: list.c
	gcc -c list.c

main.o: main.c
	gcc -c main.c

main: main.o person.o date.o list.o
	gcc -o main main.o person.o date.o list.o
