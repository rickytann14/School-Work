/*
Author: Ricardo A Garza (RicardoGarza3@my.unt.edu)
Date: 09/19/2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{	//struct for the student id and names
	int student_id;
	char student_name[100];
}student;

typedef struct
{	//struct for the course id and names
	int course_id;
	char course_name[50];
}course;

typedef struct
{
	int grade;
}grade;
typedef struct
{	//struct to keep track of names and limit
	int student_count;
	student student_list[100];
}students;

typedef struct
{	//keep track of courses and limit
	int course_count;
	course course_list[25];
}courses;

typedef struct
{	//keep track of grades
	int grade_count;
	grade grade_list[4000];
	courses course_grades[200];
	students students_grades[400];
}grades;

void addcourse(courses * add); //function to add courses
void addstudent(students * add);//function to add students
void addgrades(grades *add,students *student,courses *course);//function to add gradesfor student in course
void printstudents(students *spnt);//function to print out list of students
void printcourses(courses *cpnt);//function to print out list of courses

