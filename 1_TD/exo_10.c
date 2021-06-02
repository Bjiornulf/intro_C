#include <stdio.h>

unsigned int count_bits(int);

int main()
{
	int a = 0;
	int b = 32;
	int c = 31;
	printf("%i has %u bits set to 1\n", a, count_bits(a));
	printf("%i has %u bits set to 1\n", b, count_bits(b));
	printf("%i has %u bits set to 1\n", c, count_bits(c));
}

unsigned int count_bits(int a)
{
	unsigned int count = 0;
	for (;a != 0; a >>= 1) {
		count += a & 1;
	}
	return count;
}
