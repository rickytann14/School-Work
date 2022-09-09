#ifndef CREW_H
#define CREW_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Base Class
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

		//virtual void print() const;

	private:
		string cname;
		string ctype;
		string cstatus;
		int cid;		
};

//Dervied Classes
class pilot :public Crew {
public:
	pilot();
	//Mutators
	void addrate(string rat);
	void addhours(int thr);

	//Accessors
	string getrate() const;
	int getHr() const;

	void print() const;
private:
	int fhours;
	string rating;
};

class copilot :public Crew {
public:
	copilot();
	//Mutators
	void addrate(string rat);
	void addhours(int hrs);

	//Accessors
	string getrate() const;
	int getHr() const;

	void print() const;
private:
	int fhours;
	string rating;
};

class cabin :public Crew {
public:
	cabin();
	//Mutators
	void addcpost(string pos);

	//Accessors
	string getPost() const;

	void print() const;
private:
	string post;
};
#endif