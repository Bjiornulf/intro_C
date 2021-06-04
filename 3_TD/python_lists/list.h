#ifndef LIST_H
#define LIST_H

int *create_list(void);
int len(int *list);
int get(int *list, int index);
void print_list(int *list);
int *append(int *list, int element);
int *insert(int *list, int element);
int *range(int lower, int upper);
int *slice(int *list, int lower, int upper);
void free_list(int *list);
void set(int *list, int index, int value);
int pop(int *list);
void del(int *list, int index);

#endif
