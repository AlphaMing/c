#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int monthNum[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
typedef struct _date {
	int year;
	int month;
} Date;
//algorithm
int Algorithm(int *, int *, int*);
//This function checks input
_Bool error(char [50], char [50]);
int main()
{
	/*
	  flag records the first day of the month
	  _flag records whether the year is a leap year
	  _Flag records how many days the month has
	  Year records the year
	*/
	int i, j, n, flag, _flag = 0, _Flag, Year;
	flag = n = Algorithm(&_Flag, &_flag, &Year);
	system("cls");
	if (flag == 0)
		flag = 7;
	printf("\t\t\t万年历\n");
	printf("\t\t\t%d年%d月", Year, _Flag);
	putchar('\n');
	printf("星期一\t星期二\t星期三\t星期四\t星期五\t星期六\t星期天\n");
	if (_flag && _Flag == 2)
		_Flag = 29;
	else
		_Flag = monthNum[_Flag - 1];
	for (i = 1; i <= _Flag; i++, flag++) {
		if (i == 1) {
			for (j = flag; j > 1; j--)
				printf("\t   ");
		}
		printf("%d\t   ", i);
		if (flag == 7) {
			putchar('\n');
			flag = 0;
		}
	}
	printf("\n");
}
_Bool error(char year[50], char month[50])
{
	int i;
	_Bool flag = true;
	for (i = 0; i < strlen(year); i++) {
		if (!(year[i] >= '0' && year[i] <= '9')) {
			flag = false;
			break;
		}
	}
	for (i = 0; i < strlen(month); i++) {
		if (!(month[i] >= '0' && month[i] <= '9')) {
			flag = false;
			break;
		}
	}
	if (!(atoi(month) >= 0 && atoi(month) <= 12))
		flag = false;
	if(!flag)
		printf("error!请重新输入日期！");
	return flag;
}
int Algorithm(int *Month, int *_flag, int *_year)
{
	Date date;
	char input[50], year[50], month[50];
	int i, sum = 0, temp = 1900;
	printf("Enter the date(e.g 2008 8):");
	gets(input);
	sscanf(input, "%s%s", year, month);
	while (!error(year, month)) {
		gets(input);
		sscanf(input, "%s%s", year, month);
	}
	date.year = atoi(year);
	date.month = atoi(month);
	if (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0)
		*_flag = 1;
	*Month = date.month;
	*_year = date.year;
	if (temp > date.year) {
		temp = date.year;
		date.year = 1900;
	}
	for (i = temp; i < date.year; i++) {
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
			sum += 366 % 7;
		}
		else
			sum += 365 % 7;
	}
	for (i = 0; i < date.month - 1; i++)
		sum += monthNum[i] % 7;
	if (date.month > 2)
		sum += *_flag;
	sum = (sum + 1) % 7;
	return sum;
}
