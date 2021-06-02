#ifndef PERSONNE_H
#define PERSONNE_H
#include "date.h"

typedef struct Person Person;
Person *create_person(char *first_name, char *last_name, Date *birth_date);
Person *duplicate_person(Person *person);
void free_person(Person *person);
void print_person(Person *person);

#endif
