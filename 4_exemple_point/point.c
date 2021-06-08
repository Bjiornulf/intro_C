#include <stdio.h>
#include <stdlib.h>
#include "point.h"

void move(Point *p, int x, int y)
{
	p->x += x;
	p->y += y;
}

int dot_product(Point *p, Point *q)
{
	return (p->x * q->x) + (p->y * q->y);
}

void print_point(Point *p)
{
	printf("x = %i, y = %i\n", p->x, p->y);
}

Point *create_point(int x, int y)
{
	Point *p = (Point *) malloc(sizeof(Point));
	p->x = x;
	p->y = y;
	return p;
}
