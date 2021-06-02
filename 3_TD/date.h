#ifndef DATE_H
#define DATE_H
#define DATE_STRING_SIZE 11

typedef struct Date Date;
Date *create_date(unsigned int day, unsigned int month, unsigned int year);
Date *duplicate_date(Date *date);
void print_date(Date *date);
void date_string(Date *date, char *s);

#endif
