#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#define DEFAULT_LIST_SIZE 10

/*
	This implements lists like in python
	Creating a list return the pointer to the first value; but information is stored
	in the 2 cells before.
	These informations SHOULD NOT BE MODIFIED
*/

int *grow(int *list);

int *create_list()
{
	int *list =  (int *) malloc(sizeof(int) * (DEFAULT_LIST_SIZE + 2));
	if (list == NULL){
		return NULL;
	}
	list[0] = DEFAULT_LIST_SIZE;
	list[1] = 0;
	return list; 
}

int len(int *list)
{
	return list[1];
}

int get(int *list, int index)
{
	return list[index + 2];
}

void print_list(int *list)
{
	printf("[");
	for (int i = 0; i < len(list)-1; i++)
	{
		printf("%i,", list[i+2]);
	}
	if (len(list) != 0) {
		printf("%i", list[len(list) + 1]);
	}
	printf("]\n");
}

int *append(int *list, int element)
{
	if (list[0] == list[1]){
		list = grow(list);
		if (list == NULL)
			return NULL;
	}
	list[2+(list[1]++)] = element;
	return list;
}

int *insert(int *list, int element)
{
	if (list[1] == list[0]) {
		list = grow(list);
		if (list == NULL)
			return NULL;
	}
	for (int i = 0; i < list[1]; i++) {
		list[i+3] = list[i+2];
	}
	list[2] = element;
	list[1]++;
	return list;
}

int *grow(int *list)
{
	int prev_size = list[0];
	list = (int *) realloc(list, sizeof(*list)* (2*list[0]+2));
	if (list == NULL) {
		return NULL;
	}
	list[0] = prev_size * 2;
	return list;
}

void free_list(int *list)
{
	free(list);
}

int *slice(int *list, int lower, int upper)
{
	int *new = (int *) malloc(sizeof(*list) * (upper - lower + 1));
	if (new == NULL){
		return NULL;
	}
	new[0] = upper - lower;
	new[1] = upper - lower;
	int i,j;
	for (i = lower, j = 0; i < upper; i++, j++){
		new[j+2] = list[i+2];
	}
	return new;
}
