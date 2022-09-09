#ifndef ENROLLMENTS_H
#define ENROLLMENTS_H

#include "enroll_class.h"
#include <vector>
using namespace std;

class Enrollments {
	public:
		Enrollments();//Constructor
		void makeEnroll(Enrollment Enr);//Mutator
		void inccount();//Mutator
		void search(int id);

		void studGprnt(int id) const;//Accessor
		void studAprnt(int id) const;//Accessor
		int getcount() const;//Accessor
	private:
		int enr_cnt;
		vector<Enrollment> signup;
};
#endif
