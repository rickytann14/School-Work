#include <iostream>
#include <string>
#include "student_class.h"
using namespace std;

Student::Student(){
	sid = 0;
	sname = "none";
	classification = "none";
	
}

void Student::addFullName(string name){
	sname = name;
}

void Student::addID(int id){
	sid = id;
}

void Student::addClass(string clas){
	classification = clas;
}

string Student::getFullName() const{
	return sname;
}

string Student::getClass() const{
	return classification;
}

int Student::getID() const{
	return sid;
}

void Student::print() const{
	cout << "Student Name:  " << sname << endl;
	cout << "Student ID:    " << sid << endl;
	cout << "Student Class: " << classification << endl;
	cout << endl;
}

