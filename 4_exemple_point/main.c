#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "triangle.h"

int main()
{
	Point *p = create_point(5, 12);
	Point *q = create_point(1, 2);
	print_point(p);
	print_point(q);

	printf("move(p, 1, 0);\n");
	move(p, 1, 0);
	print_point(p);

	Point *p3 = create_point(0, 5);
	Triangle *t = create_triangle(p, q, p3);	
	print_triangle(t);

}
