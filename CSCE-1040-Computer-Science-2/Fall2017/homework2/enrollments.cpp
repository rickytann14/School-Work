#include <iostream>
#include "enrollments.h"
#include "enroll_class.h"
using namespace std;

Enrollments::Enrollments() {//Constructor
	enr_cnt = 0;
	vector<Enrollment> signup;
}

//Pushes back info for 1 Enrollment onto a collection
void Enrollments::makeEnroll(Enrollment Enr){
	signup.push_back(Enr);
}

void Enrollments::search(int id) {
	int grade;
	for (int i = 0; i < enr_cnt; i++) {
		if (id == signup[i].getEID()) {
		if (signup[i].getGCount() < 10) {
				cout << "Enter Grade for student:" << endl;
				cin >> grade;
				signup[i].setSGrade(grade);
				signup[i].setSAverage();
				signup[i].gradcount();
			}
		else { cout << "Max Number of Grades for student" << endl; }
		}
	}
}
void Enrollments::inccount() { enr_cnt++; }

int Enrollments::getcount() const { return enr_cnt; }

//General Print function
void Enrollments::studAprnt(int id) const{
	for (int i = 0; i < enr_cnt; i++) {
		if (id == signup[i].getEID()) {
			signup[i].printSAvg();
		}
	}
}

void Enrollments::studGprnt(int id) const{
	for (int i = 0; i < enr_cnt; i++) {
		if (id == signup[i].getEID()) {
			signup[i].printSGrades();
		}
	}

}