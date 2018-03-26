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
void generateDate(Date * date);
void generateName(char *name, int rnd);
void generateFulname(fulName *fulname);
void sortid(Student *student, int len);
