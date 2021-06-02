#include <stdio.h>
#include <stdlib.h>
#include "date.h"

struct Date{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};

Date *create_date(unsigned int day, unsigned int month, unsigned int year)
{
	Date *res = (Date *) malloc(sizeof(Date));
	res->day = day;
	res->month = month;
	res->year = year;
	return res;
}

Date *duplicate_date(Date *date)
{
	return create_date(date->day, date->month, date->year);
}

void print_date(Date *date)
{
	printf("%02u/%02u/%u\n",date->day, date->month, date->year);
}

void date_string(Date *date, char *s)
{
	sprintf(s, "%02u/%02u/%u", date->day, date->month, date->year);
}
