#include <stdlib.h>
#include "person.h"
#include "date.h"
#include "list.h"

int main()
{
	Date *bdate = create_date(6, 3, 2001);

	print_date(bdate);

	Person *todor = create_person("Todor", "Peev", bdate);
	print_person(todor);

	List *list = NULL;
	for (int i = 0; i < 10; i++) {
		list = insert(create_date(i, 1, 2021), list);
	}
	map_list(&void_print_date, list);
	free_list(&void_free_date, list);
	// freeing a person, frees the used date.
	free_person(todor);
}
