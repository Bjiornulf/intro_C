#include "list.h"
#include "date.h"
#include <stdlib.h>

struct List {
	Date *date;
	struct List *next;
};


List *insert(Date *date, List *list)
{
	List *head = (List *) malloc(sizeof(List));
	head->next = list;
	head->date = duplicate_date(date);
	return head;
}

void print_list(List *list)
{
	for (;list != NULL; list = list->next) {
		print_date(list->date);
	}
}

void free_list(List *list)
{
	List *temp;
	while (list != NULL) {
		temp = list->next;
		free(list->date);
		free(list);
		list = temp;
	}
}	
