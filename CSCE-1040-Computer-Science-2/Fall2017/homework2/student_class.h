#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <string>
using namespace std;

class Student{
	public:
		Student();//Constructor
		void addFullName(string name);//Mutator
		void addID(int id);//Mutator
		void addClass(string clas);//Mutator

		string getFullName() const;//Accessor
		string getClass() const;//Accessor
		int getID() const;//Accessor

		void print() const;
				
	private:
		int sid;
		string sname;
		string classification;
		//student *next;

};

#endif
