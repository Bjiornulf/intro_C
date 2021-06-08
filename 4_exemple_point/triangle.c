#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

Triangle *create_triangle(Point *p1, Point *p2, Point *p3)
{
	Triangle *t = (Triangle *) malloc(sizeof(Triangle));
	t->p1 = p1;
	t->p2 = p2;
	t->p3 = p3;
	return t;
}

void print_triangle(Triangle *t)
{
	printf("Triangle : \n");
	print_point(t->p1);
	print_point(t->p2);
	print_point(t->p3);

}
