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

int compare_date(Date *date1, Date *date2)
{
	if (date1->year < date2->year) {
		return -1;
	} else if (date1->year > date2->year) {
		return 1;
	}
	if (date1->month < date2->month) {
		return -1;
	} else if (date1->month > date2->month) {
		return 1;
	}
	if (date1->day < date2->day) {
		return -1;
	} else if (date1->day > date2->day) {
		return 1;
	}
	return 0;
}

void void_print_date(void *date)
{
	print_date((Date *) date);
}

void void_println_date(void *date)
{
	println_date((Date *) date);
}

Date *duplicate_date(Date *date)
{
	return create_date(date->day, date->month, date->year);
}

void print_date(Date *date)
{
	printf("%02d/%02d/%04d", date->day, date->month, date->year);
}

void println_date(Date *date)
{
	printf("%02d/%02d/%04d\n", date->day, date->month, date->year);
}

void free_date(Date *date)
{
	free(date);
}

void void_free_date(void *date)
{
	free((Date *) date);
}
