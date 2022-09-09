//Author:Ricardo Alberto Garza (ricardogarza3@my.unt.edu)
//Date: 9/19/2017

#include <iostream>
#include "prgm.h"
//#include "func.cpp"
using namespace std;

int main(){

	studs kids;
	cors rom;
	enrolls signup;

	kids.stu_cnt = 0;
	rom.cl_cnt = 0;
	signup.roll_cnt = 0;
	signup.grad_cnt = 0;

	kids.st_linkhead = kids.st_linktail = NULL;
	rom.cl_linkhead = rom.cl_linktail = NULL;
	signup.enr_linkhead = signup.enr_linktail = NULL;

	int choice;
	string opt = "y";
	int cnt = 0;
	string opt2;
	do{
		cout << "Please enter one of the following options:" << endl << "1.  Add a new course" << endl;
		cout << "2.  Add a new student" << endl << "3.  Add student to course" << endl;
		cout << "4.  Add grade for student in course" << endl << "5.  Print list of all grades for a student in course" << endl; 
		cout << "6.  Print list of student in a course" << endl << "7.  Compute the average for a student in a course" << endl;
		cout << "8.  Print list of courses" << endl << "9.  Print list of students" << endl;
		cout << "10. Compute the average of a course" << endl << "11. Store grade book" << endl << "12. Load grade book" << endl;
		cout << "0. Quit" << endl;
		cin >> choice;

		switch(choice){
			case 1:
				addclasses(&rom);
				break;
			case 2:
				do{
					
					addstudents(&kids);
					cnt +=1;
					cout << "Add more students? y/n" << endl;
					cin >> opt2;
					cout << "Limit is 100 "<< endl;
					cout << "Current count is: " << cnt << endl;
				}while((opt2 == opt) && (cnt <= 100));
				break;
			case 3:
				studtoclass(&signup);
				break;
			case 4:
				studgrade(&signup);
				break;
			case 5:
				studgradprint(&signup);
				break;
			case 6:
				studinclass(&signup);
				break;
			case 7:
				studavg(&signup);
				break;
			case 8:
				classprint(&rom);
				break;
			case 9:
				student_print(&kids);
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			default:
				if((choice > 12) || (choice < 0)){
					cout << " Entered wrong choice please try again" << endl;
				}
				break;
			}
	}while(choice != 0);

	//do cleanup
	cleanup_stud(&kids);
	cleanup_course(&rom);
	cleanup_enrol(&signup);
return 0;
}
