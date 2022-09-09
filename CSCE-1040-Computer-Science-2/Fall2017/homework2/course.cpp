#include <iostream>
#include <string>
#include "course_class.h"
using namespace std;

Course::Course(){//Constructor
	id = 0;
	name = "none";
	location = "none";
	meeting = "none";
}

//Sets name
void Course::setName(string cname){
	name = cname;
}

//Sets lcoation
void Course::setlocation(string cloc){
	location = cloc;
}

//Sets meeting time
void Course::setmeet(string cmeeting){
	meeting = cmeeting;
}


//Sets id
void Course::setId(int ID){
	id = ID;
}

//Returns Name, Location, Time and ID
string Course::getname() const{
	return name;
}

string Course::getloc() const{
	return location;
}

string Course::getmeet() const{
	return meeting;
}

int Course::getid() const{
	return id;
}

//Prints out infor for 1 Course
void Course::print() const{
	cout << "Course Name:     " << name << endl;
	cout << "Course ID:       " << id << endl;
	cout << "Course Location: " << location << endl;
	cout << "Course Time:     " << meeting << endl;
	cout << endl;
}