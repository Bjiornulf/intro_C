all: mkdir_obj main

mkdir_obj:
	mkdir -p obj

main: main.o triangle.o point.o
	cd obj && gcc -o ../main main.o triangle.o point.o

main.o: main.c 
	gcc -o obj/main.o -c main.c

triangle.o: triangle.c
	gcc -o obj/triangle.o -c triangle.c

point.o: point.c
	gcc -o obj/point.o -c point.c

clean:
	rm -r obj/*.o main
