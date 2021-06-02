#include <stdio.h>

unsigned int mylen(char *s);
int main()
{
	char s[] = "abcd";
	printf("mylen(%s) = %u\n", s, mylen(s));
}

unsigned int mylen(char *s)
{
	unsigned int res;
	for (res = 0; *s != '\0'; s++)
		res++;
	return res;
}
