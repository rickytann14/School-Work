#ifndef COURSES_CLASS_H
#define COURSES_CLASS_H

#include "course_class.h"
#include <vector>
using namespace std;

class Courses{
	public:
		Courses();//constructor
		void setCourse(Course Cor);//Mutator
		void inccount();//Mutator

		void prnt() const; //accessor
		int getcount() const;//accessor

	private:
		int cor_cnt;
		vector<Course> classlist;
		//course head;
		//course tail;
};
#endif