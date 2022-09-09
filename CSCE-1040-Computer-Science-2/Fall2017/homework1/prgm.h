#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

//struct for student
typedef struct student{
	int stud_id;
	char stu_name[80];
	student *next;
}stud;

//struct for class
typedef struct course{
	int cur_id;
	char  cur_name[80];
	course *next;
}cor;

//struct for list of classes
typedef struct courses{
	int cl_cnt; //class counter
	cor *cl_linkhead;
	cor *cl_linktail;
}cors;

//struct for list of students
typedef struct students{
	int stu_cnt;//student counter
	stud *st_linkhead;
	stud *st_linktail;
}studs;

typedef struct enrollment{
	int enroll_id;
	int grade[10];
	//int grade1, grade2, grade3 , grade4, grade5;
	//int grade6, grade7, grade8, grade9, grade10;
	int avg;
	int stud_loc;
	int cor_loc;
	struct enrollment *next;	
}enroll;

typedef struct enrollments{
	int roll_cnt;
	int grad_cnt;
	int studavg;
	enroll *enr_linkhead;
	enroll *enr_linktail;
}enrolls;

//function prototypes
void addstudents(studs *ppl);
void addclasses(cors *schol);
void studtoclass(enrolls *atten);
void studgrade(enrolls *atten);
void studavg(enrolls *atten);
void studgradprint(enrolls *atten);
void student_print(studs *ppl);
void classprint(cors *schol);
void studinclass(enrolls *atten);
void savef();
void loadf();
void cleanup_stud(studs *enrol);
void cleanup_course(cors *enrol);
void cleanup_enrol(enrolls *atten);
//int search(int x);