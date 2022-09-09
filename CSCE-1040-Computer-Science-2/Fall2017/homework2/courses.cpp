#include <iostream>
#include "courses_class.h"
#include "course_class.h"

using namespace std;

Courses::Courses() {//Constructor
	cor_cnt = 0;
	vector<Course> classlist;
}

//Pushes back info for 1 course onto vector
void Courses::setCourse(Course Cor){
	classlist.push_back(Cor);
}

int Courses::getcount() const { return cor_cnt; }

void Courses::inccount() { cor_cnt++; }

//Print fuction
void Courses::prnt() const{
	int cor_cnt = getcount();
	for (int i = 0; i < cor_cnt; i++) {
		classlist[i].print();
	}
}