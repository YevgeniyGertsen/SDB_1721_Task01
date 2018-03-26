#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include "Header.h"
#include <Windows.h>
#include<fstream>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

struct Group
{
	fulName *name;
	Date *date;
	int *ses;
};

void main()
{
	setlocale(0, "");
	srand(time(0));
	Student *student = (Student*)malloc(sizeof(Student) * 20);
	if (student == NULL)
	{
		printf("ѕам€ть не выделена\n");
		system("exit");
	}
	else
	{
		double totalsum = 0;
		ofstream file("C:\\1\\students.txt");
		for (int i = 0; i < 20; i++)
		{
			(student + i)->id = 0 + rand() % 1000;
			(student + i)->name = (char*)malloc(sizeof(char) * 30);
			(student + i)->course = (char*)malloc(sizeof(char) * 30);
			(student + i)->ses = (int*)malloc(sizeof(int) * 5);

			generateName((student + i)->name, 30);
			generateName((student + i)->course, 30);
			int sum = 0;

			for (int j = 0; j < 5; j++)
			{
				(student + i)->ses[j] = 2 + rand() % 3;
				sum += (student + i)->ses[j];
			}
			(student + i)->sred = sum / 5;
			totalsum += (student + i)->sred;
		}

		totalsum = totalsum / 20;
//		Х	вывод на экран записей, упор€доченного списка студентов, средний бал которых превышает общий средний бал;

		printf("—редний балл студентов=%2.2lf\n", totalsum);
		printf("--------------------------------------\n");

		sortid(student, 20);
		int check = 0;
		for (int i = 0; i < 20; i++)
		{
			if ((student + i)->sred > totalsum)
			{
				check++;
				SetConsoleTextAttribute(hConsole, 12);
				printf("#ID %d %s (%2.2lf)\n", 
					(student + i)->id, (student + i)->name, (student+i)->sred);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 15);
				printf("#ID %d %s (%2.2lf)\n",
					(student + i)->id, (student + i)->name, (student + i)->sred);
			}
		}

		SetConsoleTextAttribute(hConsole, 15);
		printf("--------------------------------------\n");
		printf(" ол-во студентов выше сред балла(%2.2lf) = %d\n", totalsum,check);
		printf("--------------------------------------\n");
		for (int i = 0; i < 20; i++)
		{
			file<< (student + i)->id<<" "<<(student + i)->name<<" "<<(student + i)->sred<<endl;
		}

	}




#pragma region 



	/*1.	ќписать структуру с именем GROUP, содержащую пол€ :
	a.Name Ц фамили€ и инициалы
	b.DAT Ц дата рождени€(год, мес€ц, число)
	c.SES Ц успеваемость(массив из трех элементов).*/

	/*int n;
	printf("¬ведите кол-во €чеек в вашем массиве \n");
	scanf("%d", &n);
	Group *mas = (Group *)malloc(n * sizeof(Group));
	for (int i = 0;i < n;i++)
	{
		(mas + i)->date = new Date[1];
		generateDate((mas + i)->date);

		(mas + i)->name = new fulName[1];
		generateFulname((mas + i)->name);
	}
	for (int i = 0;i < n;i++) {

		if ((2018 - (mas + i)->date->year) > 20)
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "# " << i + 1 << ") ";
			cout << (mas + i)->date->day << "." << (mas + i)->date->month << "." << (mas + i)->date->year << endl;
			cout << (mas + i)->name->fname << " " << (mas + i)->name->lname << " " << (mas + i)->name->name << " " << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << "# " << i + 1 << ") ";
			cout << (mas + i)->date->day << "." << (mas + i)->date->month << "." << (mas + i)->date->year << endl;
			cout << (mas + i)->name->fname << " " << (mas + i)->name->lname << " " << (mas + i)->name->name << " " << endl;
		}

	}
	SetConsoleTextAttribute(hConsole, 15);*/

#pragma endregion



}