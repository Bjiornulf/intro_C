#include <stdio.h>
#define MAX_INPUT 1000

void readline(char[], const char *message);
int compare_string(char s1[], char s2[]);

int main()
{
	char s1[MAX_INPUT], s2[MAX_INPUT];
	readline(s1, "entrez la chaine de caracteres 1");
	readline(s2, "entrez la chaine de caracteres 2");	
	printf("compare_string(s1, s2) -> %i\n", compare_string(s1, s2));
}

void readline(char s[], const char *message)
{
	printf("%s : ", message);
	char c;
	int i = 0;
	while ((c = getchar()) != '\n' && c != EOF)
		s[i++] = c;
	s[i] = '\0';
}

int compare_string(char s1[], char s2[])
{
	int i;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++){
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	if (s1[i] < s2[i])
		return -1;
	if (s1[i] > s2[i])
		return 1;
	return 0;
}

