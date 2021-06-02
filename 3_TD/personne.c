#include "personne.h"
#include "date.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person {
	Date *birth_date;
	char *first_name;
	char *last_name;
};

Person *create_person(char *first_name, char *last_name, Date *birth_date)
{
	Person *person = (Person *) malloc(sizeof(Person));
	person->birth_date = duplicate_date(birth_date);
	person->first_name = (char *) malloc(strlen(first_name) + 1);
	person->last_name = (char *) malloc(strlen(last_name) + 1);
	strcpy(person->first_name, first_name);
	strcpy(person->last_name, last_name);
	return person;
}

Person *duplicate_person(Person *person)
{
	Person *duplicate = create_person(person->first_name, person->last_name, person->birth_date); 
	return duplicate;
}

void free_person(Person *person)
{
	free(person->first_name);
	free(person->last_name);
	free(person->birth_date);
	free(person);
}

void print_person(Person *person)
{
	char birth_date[DATE_STRING_SIZE];
	date_string(person->birth_date, birth_date);
	printf("%s %s born the %s\n", person->first_name, person->last_name, birth_date);
}
