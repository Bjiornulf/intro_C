#include <stdio.h>
#include "secret.h"

int main()
{
	List *list = create_list(10);
	for (int i = 0; i<10; i++)
	{
		push_list(i, list);
	}
	for (int i = 0; i<10; i++)
	{
		printf("list->arr[%i] = %i\n", i, list->arr[i]);
	}
	free_list(list);
}
