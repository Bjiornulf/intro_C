#ifndef DATE_H
#define DATE_H

typedef struct _Date {
	int day;
	int month;
	int year;
} Date;

Date *create_date(int day, int month, int year);
int compare_date(Date *date1, Date *date2);
Date *duplicate_date(Date *date);
void print_date(Date *date);
void void_print_date(void *date);
void free_date(Date *date);
void void_free_date(void *date);

#endif
