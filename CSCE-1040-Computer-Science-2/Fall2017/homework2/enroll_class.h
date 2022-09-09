#ifndef ENROLL_CLASS_H
#define ENROLL_CLASS_H

#include <string>
#include <vector>
using namespace std;

class Enrollment{
	private:
		int stud_id, cor_id, enr_id;
		string stud_name, cor_name;
		vector<int> stud_grade;
		int stud_avg, cor_avg;
		int grad_cnt;
	public:
		Enrollment();//Constructor
		void setSName(string sname);//Mutator
		void setCName(string cname);//Mutator
		void setSID(int stu_id);//Mutator
		void setCID(int cla_id);//Mutator
		void setEID(int e_id);//Mutator
		void setSGrade(int sgrade);//Mutator
		void setSAverage();//Mutator
		void setCAverage(int Cavg);//Mutator
		void gradcount();//Mutator

		string getSName() const;//Accessor
		string getCName() const;//Accessor
		int getSID() const;//Accessor
		int getCID() const;//Accessor
		int getEID() const;//Accessor
		int getSAvg() const;//Accessor
		int getCAvg() const;//Accessor
		int getGCount() const;//Accessor

		void printSGrades() const;
		void printSAvg() const;
		void printCAvg() const;
};
#endif
