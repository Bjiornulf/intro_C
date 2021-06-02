#include "date.h"
#include "personne.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Date *date1 = create_date(6, 3, 2001);	
	Date *date2 = create_date(31, 12, 2021);
	char first_name[] = "Todor";
	char last_name[] = "Peev";
	Person *todor = create_person(first_name, last_name, date1);
	print_date(date1);
	print_date(date2);
	print_person(todor);

	List *list = NULL;
	list = insert(date1, list);
	list = insert(date2, list);
	print_list(list);

	// freeing memory
	free_person(todor);
	free_list(list);
	free(date1);
	free(date2);
}
