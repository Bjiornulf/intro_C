#include <stdlib.h>
#include "list.h"

List *push_list(void *data, List *list)
{
	if (list == NULL) {
		List *new = (List *) malloc(sizeof(List));
		new->data = data;
		new->next = NULL;
		return new;
	}
	if (list->data == NULL){
		list->data = data;
		return list;
	}
	List *new = (List *) malloc(sizeof(List));
	new->next = list;
	new->data = data;
	return new;
}

List *create_list(void *data)
{
	List *list = (List *) malloc(sizeof(List));
	list->next = NULL;
	list->data = data;
	return list;
}

void map_list(void (*func)(void *), List *list)
{
	while(list != NULL) {
		func(list->data);
		list = list->next;
	}
}

void free_list(void (*free_data)(void *), List *list){
	List *temp = list;
	while(list != NULL) {
		free_data(list->data);
		temp = list->next;
		free(list);
		list = temp;
	}
}
