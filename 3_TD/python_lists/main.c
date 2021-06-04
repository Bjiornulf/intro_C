#include <stdio.h>
#include "list.h"

int main()
{
	int *list = create_list();
	for (int i = 0; i < 50; i++){
		list = append(list, i);
	}

	print_list(list);
	int *s = slice(list, 10, 40);
	print_list(s);
	printf("len(list) = %i\n", len(list));
	printf("len(s) = %i\n", len(s));

	del(list, 10);
	print_list(list);
	printf("len(list) = %i\n", len(list));
	free_list(s);
	free_list(list);
}
