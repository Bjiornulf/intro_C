#include <stdio.h>

int main()
{
	int t[3];
	for (int i = 0; i < 10000; i++) {
		printf("t[%d] = %d\n", i, t[i]);
	}
}
