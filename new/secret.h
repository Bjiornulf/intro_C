#ifndef SECRET_H
#define SECRET_H

struct List {
	int *arr;
	unsigned int size;
	unsigned int last;
};
typedef struct List List;
List *create_list(unsigned int size);
int push_list(int value, List *list);
int double_list(List *list);
int free_list(List *list);

#endif
