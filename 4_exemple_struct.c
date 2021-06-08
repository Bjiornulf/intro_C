#include <stdlib.h>

typedef struct _Point {
	int x;
	int y;
} Point;

void move(Point *p);

int main()
{
	Point *p = (Point *) malloc(sizeof(Point));

	move(p);
}

void move(Point *p)
{
	p->x += 1;
}
