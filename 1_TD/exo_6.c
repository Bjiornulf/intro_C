#include <stdio.h>
#define MAX_INPUT 10000

int main()
{
	char input[MAX_INPUT+1], c;
	int i = 0;
	while((c = getchar()) != '\n' && c != EOF)
		input[i++] = c;
	input[i] = '\0';
	printf("your input was : %s\n", input);
}
