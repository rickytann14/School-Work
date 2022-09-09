#ifndef CREW_H
#define CREW_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Crew{
	public:
		Crew();//constructor
		void addCName(string nam);//Mutators
		void addIDnum(int id);
		void addType(string ty);
		void addStatus(string stat);

		string getCName() const;//Accessor Functions
		int getID() const;
		string getType() const;
		string getStatus() const;

		void print() const;

	private:
		string cname;
		string ctype;
		string cstatus;
		int cid;		
};

#endif