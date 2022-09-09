#ifndef COURSE_CLASS_H
#define COURSE_CLASS_H

#include <string>
using namespace std;

class Course{
	private:
		int id;
		string name;
		string location;
		string meeting;
	public:
		void setName(string cname);//Mutator
		void setlocation(string cloc);//Mutator
		void setmeet(string cmeeting);//Mutator
		void setId(int ID);//Mutator

		string getname() const;//Accessor
		string getloc() const;//Accessor
		string getmeet() const;//Accssor
		int getid() const;//Accssor

		void print() const;//Accessor
		Course();//constructor		

};

#endif
