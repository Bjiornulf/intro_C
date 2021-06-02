#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int limit;
	// test if second argument is a valid integer
	if (argc != 2 || ((limit = atoi(argv[1])) == 0 && !(argv[1][0] == '0' && argv[1][1] == '\0'))) {
			printf("Usage : fibo n\n");
			return 1;
	}
	unsigned int prev, next;
	prev = 0;
	next = 1;
	for (int i = 0; i < limit; i++) {
			next += prev;
			prev = next - prev;
	}
	printf("%i\n", prev);
	return 0;
}
