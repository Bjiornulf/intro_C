#include "person.h"
#include "date.h"

int main()
{
	Date *bdate = create_date(6, 3, 2001);

	print_date(bdate);

	Person *todor = create_person("Todor", "Peev", bdate);
	print_person(todor);
	free_date(bdate);
	free_person(todor);
}
