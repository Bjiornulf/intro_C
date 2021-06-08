#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

typedef struct _Triangle {
	Point *p1;
	Point *p2;
	Point *p3;
} Triangle;

Triangle *create_triangle(Point *p1, Point *p2, Point *p3);
void print_triangle(Triangle *t);

#endif
