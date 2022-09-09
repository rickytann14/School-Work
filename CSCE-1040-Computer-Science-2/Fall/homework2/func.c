#include "prgm.h"

void addstudent(students * add)//function to add students
{
	int id;
	char name[100];
	student *temp;

	temp = (student*) malloc(sizeof(student));
	printf("Please enter student ID: ");
	scanf("%d%*c", &(temp->student_id));
	printf("Please enter student name: ");
	fgets(temp->student_name,100,stdin);

	temp->next=NULL;

	if(add->student_count==0)
	{
		add->student_list_head = add->student_list_tail = temp;
	}
	else
	{
		add->student_list_tail->next=temp;
		add->student_list_tail = temp;
	}

	add->student_count +=1;
}

void addcourse(courses * add) //function to add courses
{
	int id;
	char name[100];
        course *temp;

	temp = (course*) malloc(sizeof(course));
        printf("Please enter Course ID: ");
        scanf("%d%*c", &(temp->course_id));
        printf("Please enter Course name: ");
        fgets(temp->course_name,100,stdin);

	if(add->course_count==0)
	{
		add->course_list_head = add->course_list_tail = temp;
	}
	else
	{
		add->course_list_tail->next=temp;
		add->course_list_tail = temp;
	}
        add->course_count +=1;
}
/*
void addgrades(grades *add,students *student,courses *course)//function to add gradesfor student in course
{
	int id, i;
	char *temp;
	printf("Please enter Student ID: ");
	scanf("%d%*c", &(temp ->student_id));
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
*/
void printstudents(students *spnt)//function to print out list of students
{
	student *temp;
	temp = spnt ->student_list_head;
	int i;
	while(temp != NULL)
	{
		student *temp2;
		temp2 = temp->next;
		printf("Student ID:%d  Name:%s\n", temp->student_id, temp->student_name);
		temp = temp2;
	}
}

void printcourses(courses *cpnt)//function to print out list of courses
{
        int i;
	course *temp;
	temp = cpnt -> course_list_head;
        while(temp != NULL)
        {
		course *temp2;
		temp2 = temp->next;
                printf("Course ID:%d  Name:%s\n", temp->course_id, temp->course_name);
		temp = temp2;
        }
}
