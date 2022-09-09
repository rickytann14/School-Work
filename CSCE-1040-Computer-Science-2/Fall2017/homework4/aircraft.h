#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
using namespace std;

class Aircraft{
	public:
		Aircraft();//Constructor
		void addModel(string mod);//Mutator
		void addMake(string mak);//Mutator
		void addstatus(string stat);//Mutator
		void addseat(int seatnum);//Mutator
		void addtail(string tailnum);//Mutator
		void addrange(int dist);//Mutator

		string getModel() const;//Accessor
		string getMake() const;//Accessor
		string getStatus() const;//Accessor
		int getSeatNum() const;//Accessor
		string getTailNum() const;//Accessor
		int getRange() const;//Accessor

		void print() const;

	private:
		string model;
		string make;
		string status;
		int seat_num;
		string tail_num;
		int range;

};

#endif
