#include <stdlib.h>
#include "secret.h"


List *create_list(unsigned int size)
{
	List *list = (List *) malloc(sizeof(List));
	list->size = size;
	list->last = -1;
	list->arr = (int *) malloc(sizeof(int) * size);
	return list;
}

int double_list(List *list)
{
	int *new = (int *) realloc(list->arr, sizeof(int) * list->size * 2);
	if (new == NULL)
		return 0;
	list->arr = new;
	list->size *= 2;
	return 1;
}

int push_list(int value, List *list)
{
	if (list->last == list->size - 1)
	{
		if (double_list(list))
		{
			list->last += 1;
			(list->arr)[list->last] = value;
			return 1;
		} else {
			return 0;
		}
	}

	(list->arr)[++list->last] = value;
	return 1;
}

int free_list(List *list)
{
	free(list->arr);
	free(list);
}
