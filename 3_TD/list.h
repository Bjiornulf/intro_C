#ifndef LIST_H
#define LIST_H

#include "date.h"

typedef struct List List;
List *insert(Date *date, List *list);
void free_list(List *list);
void print_list(List *list);


#endif
