#include <stdio.h>

unsigned int mylen(char s[]);

int main()
{
	char s[] = "this is a string";
	printf("\"%s\" is a string, and its length is %u\n", s, mylen(s));
}

unsigned int mylen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		;
	return i;
}
