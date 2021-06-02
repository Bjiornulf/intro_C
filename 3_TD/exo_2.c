#include <stdio.h>
#include <stdlib.h>

unsigned int count_occ(char *s, char c);
void copy_string(char origin[], char *destination);

int main()
{
	char s[] = "some text";
	char *s2 = (char *) malloc(sizeof(char) * 10);
	copy_string(s, s2);
	printf("s2 = %s\n", s2);
	printf("in \"%s\" there is %i times \'%c\'\n", s, count_occ(s, 'e'), 'e');
	free(s2);
}

unsigned int count_occ(char *s, char c)
{
	int count;
	for (count = 0; *s; s++) {
		if (*s == c) {
			count++;
		}
	}
	return count;
}

void copy_string(char origin[], char *destination)
{
	for (;*origin;origin++) {
		*(destination++) = *origin;
	}
	*destination = '\0';
}
