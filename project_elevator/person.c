#include <stdlib.h>
#include "person.h"

Person *create_person(int src, int dest)
{
	Person *person = (Person *) malloc(sizeof(Person));
	person->src = src;
	person->dest = dest;

	return person;
}

PersonList *insert(Person *p, PersonList *list)
{
	PersonList *head = (PersonList *) malloc(sizeof(PersonList));
	head->person = p;
	head->next = list;

	return head;
}

int length_list(PersonList *list)
{
	int len = 0;
	for (;list != NULL; list = list->next)
		len++;
	return len;
}

PersonList *reverse_list(PersonList *list)
{
	PersonList *new = NULL;
	PersonList *temp;
	while (list != NULL) {
		temp = list->next;
		list->next = new;
		new = list;
		list = temp;
	}
	return new;
}

void free_list(PersonList *list)
{
	PersonList *temp;
	while (list != NULL){
		temp = list->next;
		free(list->person);
		free(list);
		list = temp;
	}
}
