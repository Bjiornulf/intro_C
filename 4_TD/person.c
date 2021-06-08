#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person *create_person(char *first_name, char *last_name, Date* birth_date)
{
	/* creating a person will copy the name */
	Person *p = (Person *) malloc(sizeof(Person));
	p->first_name = (char *) malloc(sizeof(strlen(first_name) + 1));
	p->last_name = (char *) malloc(sizeof(strlen(last_name) + 1));
	strcpy(p->first_name, first_name);
	strcpy(p->last_name, last_name);
	p->birth_date = birth_date;

	return p;
}

void print_person(Person *p)
{
	printf("Person : \n");
	printf("first name : %s\n", p->first_name);
	printf("last name : %s\n", p->last_name);
	printf("birth date : "), print_date(p->birth_date);
}

void free_person(Person *p)
{
	free(p->first_name);
	free(p->last_name);
	free(p);
}
