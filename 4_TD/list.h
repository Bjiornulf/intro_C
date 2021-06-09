#ifndef LIST_H
#define LIST_H

typedef struct _List {
	void *data;
	struct _List *next;
} List;

List *push_list(void *data, List *list);
List *create_list(void *data);
void map_list(void (*func)(void*), List *list);
void free_list(void (*free_data)(void *), List *list);

#endif
