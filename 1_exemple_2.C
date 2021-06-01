#include <stdio.h>

int main()
{
	int t[3];
	
	t[0] = 5;
	t[1] = 65;

	printf("65 vu comme entier : %d\n", t[1]);
	printf("65 vu comme caractere : %c\n", t[1]);
	
	char b = t[1] + 1;
	printf("B = %d <--> %c\n", b, b);

	printf("Et ici on regarde une case qui n'a pas ete initialisee dans le tableau : t[2] = %d\n", t[2]);

	printf("Et ici on regarde t[3] (on peut se faire engueuler) : t[3] = %d\n", t[3]);
}
