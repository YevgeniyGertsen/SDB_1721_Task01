#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <time.h>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

struct fulName
{
	char  *fname;
	char *lname;
	char *name;
};

struct Student
{
	int id;
	char *name;
	char *course;
	int *ses;
	double sred;
};

void generateDate(Date * date)
{
	
	date->day = 0 + rand() % 30;
	date->month = 1 + rand() % 11;
	date->year = 1818 + rand() % 200;
}

void generateName(char *name, int rnd) 
{
	int r = 0;
	for (int i = 0; i < rnd-1; i++)
	{
		r = 192 + rand() % 60;
		char t = (char)r;
		name[i] = (char)r;
	}
	name[rnd] = '\0';
}

void generateFulname(fulName *fulname) {
	
	int rnd = 2 + rand() % 8;
	fulname->fname = new char[rnd];

	generateName(fulname->fname, rnd);

	rnd = 2 + rand() % 8;
	fulname->lname = new char[rnd];	
	generateName(fulname->lname, rnd);

	rnd = 2 + rand() % 8;
	fulname->name = new char[rnd];
	generateName(fulname->name, rnd);
}

void sortid(Student *student,int len)
{
	Student st;
	for (int i = 0; i < len; i++)
	{
		for (int j = len-1; j > i; j--)
		{
			if ((student + j)->id < (student + j - 1)->id)
			{
				st = *(student + j);
				*(student + j) = *(student + j - 1);
				*(student + j - 1) = st;
			}
		}
	}
}
