#include <stdio.h>

int is_palindrome(char s[]);

int main()
{
	char s[] = "abcddcba";
	char s2[] = "test";
	printf("is_palindrome(%s) -> %i\n", s, is_palindrome(s));
	printf("is_palindrome(%s) -> %i\n", s2, is_palindrome(s2));
}

int is_palindrome(char s[])
{
	int i, j;
	// setting j to the last index of the word
	for (j = 0; s[j] != '\0'; j++)
		;
	j--;
	for (i = 0; i < j; i++, j--){
		if (s[i] != s[j])
			return 0;
	}
	return 1;
}
