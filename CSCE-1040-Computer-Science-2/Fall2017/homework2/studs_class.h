#ifndef STUDS_CLASS_H
#define STUDS_CLASS_H

#include "student_class.h"
#include <vector>
using namespace std;

class Students{
	public:
		Students();// {studs_cnt = 0;}
		void setStudent(Student stud);
		void inccount();


		void prnt() const;//accsesor
		int getcount() const;//accessor
	private:
		int studs_cnt;
		vector<Student> kidlist;
};

#endif
