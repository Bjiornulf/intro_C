#ifndef PERSON_H
#define PERSON_H
#include "date.h"

typedef struct _Person {
	char *first_name;
	char *last_name;
	Date *birth_date;
} Person;

Person *create_person(char *first_name, char *last_name, Date *date);
void print_person(Person *p);
void free_person(Person *p);

#endif
