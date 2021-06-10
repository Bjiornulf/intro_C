#ifndef PERSON_H
#define PERSON_H

typedef struct _Person {
	int src;
	int dest;
} Person;

typedef struct _PersonList {
	Person *person;
	struct _PersonList *next;
} PersonList;

Person* create_person(int src, int dest);
PersonList* insert(Person *p, PersonList *list);
int length_list(PersonList *list);
PersonList *reverse_list(PersonList *list);
void free_list(PersonList *list);

#endif
