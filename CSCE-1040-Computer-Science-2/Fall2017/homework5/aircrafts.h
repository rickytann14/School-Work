#ifndef AIRCRAFTS_H
#define AIRCRAFTS_H
#include <vector>
#include "aircraft.h"

class Aircrafts{
	public:
		Aircrafts();//Construcor
		void addCraft();//Functions
		void deleteCraft();
		void editCraft();
		int searchCraft(int x);
		void printall();
		void print(int num);

		int downcount();
		int getcount() const;//Accessor
		int upcount();//Muator
		string getStatus(int temp);
		string getTail(string temp, int tx);

	private:
		vector<Aircraft> plane;
		int air_count;
};

#endif
