#ifndef POINT_H
#define POINT_H

typedef struct _Point {
	int x;
	int y;
} Point;

void move(Point *p, int x, int y);
int dot_product(Point *p, Point *q);
void print_point(Point *p);
Point *create_point(int x, int y);

#endif
