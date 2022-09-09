#include <iostream>
#include "studs_class.h"
#include "student_class.h"

using namespace std;

Students::Students(){
	studs_cnt = 0;
	vector<Student> kidlist;
}

void Students::setStudent(Student stud){
	kidlist.push_back(stud);
	return;
}

int Students::getcount() const{return studs_cnt;}

void Students::inccount(){studs_cnt++;}

void Students::prnt() const{
	int studs_cnt = getcount();
	for(int i = 0; i< studs_cnt; i++){
		cout << "Student Name:           "<< kidlist[i].getFullName() << endl;
		cout << "Student ID:             "<< kidlist[i].getID() << endl;
		cout << "Student Classification: "<< kidlist[i].getClass() << endl;
		cout << endl;
	}
	return;
}
