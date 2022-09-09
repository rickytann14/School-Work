#include <iostream>
#include <string>
#include "enroll_class.h"
using namespace std;

Enrollment::Enrollment() {
	stud_id = 0;
	cor_id = 0;
	enr_id = 0;
	stud_name = "none";
	cor_name = "none";
	stud_avg = 0;
	cor_avg = 0;
	grad_cnt = 0;

}

//Sets student Name, ID, Average, and Grades
//Sets course Name, ID, Average 
void Enrollment::setSName(string sname){
	stud_name = sname;
}

void Enrollment::setCName(string cname){
	cor_name = cname;
}

void Enrollment::setSID(int stu_id){
	stud_id = stu_id;
}

void Enrollment::setCID(int cla_id){
	cor_id = cla_id;
}

void Enrollment::setEID(int e_id){
	enr_id = e_id;
}

void Enrollment::setSAverage(){
	int sum = 0;
	for (int i = 0; i < grad_cnt; i++) {
		sum = stud_grade[i] + sum;
	}
	if (grad_cnt != 0) {
		stud_avg = sum / grad_cnt;
	}
	else { stud_avg = sum; }
}

void Enrollment::setSGrade(int sgrade){
		stud_grade.push_back(sgrade);
}

void Enrollment::gradcount() {
	if (grad_cnt < 10) {
		grad_cnt++;
		return;
	}
	else { cout << "Max number of grades!!" << endl; }
}

//Returns Students Name, ID, Grades, and Average
//Returns Course Name, ID, Average
string Enrollment::getSName() const{
	return stud_name;
}

string Enrollment::getCName() const{
	return cor_name;
}

int Enrollment::getSID() const{
	return stud_id;
}

int Enrollment::getCID() const{
	return cor_id;
}

int Enrollment::getEID() const {
	return enr_id;
}

int Enrollment::getSAvg() const{
	return stud_avg;
}

int Enrollment::getCAvg() const{
	return cor_avg;
}

int Enrollment::getGCount() const{
	return grad_cnt;
}

void Enrollment::printSGrades() const{
	for (int i = 0; i < grad_cnt; i++) {
		cout << "Grade" << i+1 << ": " << stud_grade[i] << endl;
	}
}

void Enrollment::printSAvg() const{
	if (getSAvg() > 89) {
		cout << "Student Avgrage Grade: A" <<  endl;
	}

	if (stud_avg > 79) {
		cout << "Student Average Grade: B" << endl;
	}

	if (stud_avg > 69) {
		cout << "Student Average Grade: C" << endl;
	}
	else if(stud_avg <= 69) { 
		cout << "Student is Failing This Class: " << cor_name << endl; 
	}
	cout << endl;
}