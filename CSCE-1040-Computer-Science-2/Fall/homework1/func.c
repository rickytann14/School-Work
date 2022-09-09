#include "prgm.h"

void addstudent(students * add)//function to add students
{
	int id;
	char temp[100];
	printf("Please enter student ID: ");
	scanf("%d%*c", &(add->student_list[add->student_count].student_id));
	printf("Please enter student name: ");
	fgets(add->student_list[add->student_count].student_name,100,stdin);
	add->student_count +=1;
}

void addcourse(courses * add) //function to add courses
{
	int id;
        char temp[100];
        printf("Please enter Course ID: ");
        scanf("%d%*c", &(add->course_list[add->course_count].course_id));
        printf("Please enter Course name: ");
        fgets(add->course_list[add->course_count].course_name,100,stdin);
        add->course_count +=1;
}

void addgrades(grades *add,students *student,courses *course)//function to add gradesfor student in course
{
	int id, i;
	char temp[100];
	printf("Please enter Student ID: ");
	scanf("%d%*c", &(student->student_list[student->student_count].student_id));
	for(i=0;i<(student->student_count);i++)
	{
		if(i ==(student->student_list[i].student_id))
		{
			printf("Please enter Course ID: ");
		}
		else if(i>(student->student_count))
		{
			printf("ID not in gradebook!!\n\n");
		}
	}
}
void printstudents(students *spnt)//function to print out list of students
{
	int i;
	for(i=0;i < (spnt->student_count);i++)
	{
		printf("Student ID:%d  Name:%s\n", spnt->student_list[i].student_id, spnt->student_list[i].student_name);
	}
}

void printcourses(courses *cpnt)//function to print out list of courses
{
        int i;
        for(i=0;i < (cpnt->course_count);i++)
        {
                printf("Course ID:%d  Name:%s\n", cpnt->course_list[i].course_id, cpnt->course_list[i].course_name);
        }
}

