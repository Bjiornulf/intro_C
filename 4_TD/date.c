#include "date.h"
#include <stdlib.h>
#include <stdio.h>

Date *create_date(int day, int month, int year)
{
	Date *date = (Date *) malloc(sizeof(Date));
	date->day = day;
	date->month = month;
	date->year = year;
	return date;
}

void print_date(Date *date)
{
	printf("%02d/%02d/%04d\n", date->day, date->month, date->year);
}

void free_date(Date *date)
{
	free(date);
}
