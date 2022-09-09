#ifndef CREWS_H
#define CREWS_H
#include <vector>
#include "crew.h"

class Crews{
	public:
		Crews();//Constructor
		void addCrew();//Functions
		void deleteCrew();
		void editCrew();
		int searchCrew(int temp);
		void print(int temp2);
		void printall();

		int downcount();//Mutator
		int upcount();

		int getcount() const;//Accessors
		string gettype(int temp);
		int getID(int temp);
		string getName(int temp);
		string getStatus(int temp);

private:
	int crew_count;
	vector<Crew> ppl;
};

#endif // !CREWS_H

