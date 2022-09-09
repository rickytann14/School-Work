#include <iostream>
#include <string>
#include "student_class.h"
#include "studs_class.h"
#include "course_class.h"
#include "courses_class.h"
#include "enroll_class.h"
#include "enrollments.h"
using namespace std;

int main(){

	Students lkids;//student collection object
	Student kid;//student entity object
	Courses clist;//Class collection object
	Course curs;//Class entity object
	Enrollment roll;//Enrollment entity object
	Enrollments enlist;//Enrollment collection object

	int choice;

	string sname, cname, clas;//student, course name and classification
	int sid, cid, grade;//student, course id's and grades
	string loc, tmet;//location and meeting
	int eid;


	cout << "----------------------------------------------------" << endl;
	cout << "-Author: Ricardo A Garza (ricardogarza3@my.unt.edu)-" << endl;
	cout << "-Date: 10/12/2017                                  -" << endl;
	cout << "-Insturctor: David Keethly                         -" << endl;
	cout << "-Course: CSCE 1040 Fall 2017                       -" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << endl;
do{
		cout << "Please enter one of the following options:" << endl << "1.  Add a new course" << endl;
		cout << "2.  Add a new student" << endl << "3.  Add student to course" << endl;
		cout << "4.  Add grade for student in course" << endl << "5.  Print list of all grades for a student in a course" << endl; 
		cout << "6.  Print list of students in a course" << endl << "7.  Compute the average for a student in a course" << endl;
		cout << "8.  Print list of courses" << endl << "9.  Print list of students" << endl;
		cout << "10. Compute the average of a course" << endl << "11. Store grade book" << endl << "12. Load grade book" << endl;
		cout << "0. Quit" << endl;
		cin >> choice;
		cin.ignore();

		switch(choice){
			case 1:
				//User input Course Name, ID, Location, Time
				cout << "Enter Course Name:" << endl;
				getline(cin, cname);
				curs.setName(cname);
				
				cout << "Enter Course ID:" << endl;
				cin >> cid;
				curs.setId(cid);

				cin.ignore();
				cout << "Enter Course Location:" << endl;
				getline(cin, loc);
				curs.setlocation(loc);

				cout << "Enter Course Time" << endl;
				getline(cin, tmet);
				curs.setmeet(tmet);

				//Pass info to collection and add 1 to colloction count
				cin.ignore();
				clist.setCourse(curs);
				clist.inccount();
				cout << endl;

				break;
			case 2:
				//User input Student Name, ID, and Classification
				cout <<"Enter student Name:" << endl;
				getline(cin,sname);
				kid.addFullName(sname);
			
				cout <<"Enter student ID:" << endl;
				cin >> sid;
				kid.addID(sid);

				cout <<"Enter student Classification:" << endl;
				cin >> clas;
				kid.addClass(clas);

				//Pass info to collection and add 1 to collection count
				cin.ignore();
				lkids.setStudent(kid);
				lkids.inccount();
				cout << endl;
					
				break;
			case 3:
				//User input for new Enrollment
				cout << "Enter new Enrollment ID:" << endl;
				cin >> eid;
				roll.setEID(eid);

				cin.ignore();
				cout << "Enter Student Name:" << endl;
				getline(cin, sname);
				roll.setSName(sname);

				cout << "Enter Student ID:" << endl;
				cin >> sid;
				roll.setSID(sid);

				cin.ignore();
				cout << "Enter Course Name:" << endl;
				getline(cin, cname);
				roll.setCName(cname);

				cout << "Enter Course ID:" << endl;
				cin >> cid;
				roll.setCID(cid);

				cin.ignore();
				enlist.makeEnroll(roll);
				enlist.inccount();
				cout << endl;
				break;
			case 4:
				cout << "Enter Enrollment ID:" << endl;
				cin >> eid;
				enlist.search(eid);
				break;
			case 5:
				cout << "Enter Enrollment ID:" << endl;
				cin >> eid;
				enlist.studGprnt(eid);
				break;
			case 6:
				break;
			case 7:
				//Print Average for student in Course
				cout << "Enter Enrollment ID:" << endl;
				cin >> eid;
				enlist.studAprnt(eid);
				break;
			case 8:
				//Print list of Courses
				clist.prnt();
				break;
			case 9:
				//Print list of Students
				lkids.prnt();
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
}
