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

		int downcount();//Mutator counters
		int upcount();
		void pup();
		void copup();
		void caup();
		void pdown();
		void copdown();
		void cadown();

		int getcount() const;//Accessors
		string gettype(int temp);
		int getID(int temp);
		string getName(int temp);
		string getStatus(int temp);

private:
	int crew_count, pilot_count;
	int copi_count, cabin_count;
	vector<Crew> ppl;
	vector<pilot> lead;
	vector<copilot> flow;
	vector<cabin> noth;
};

#endif // !CREWS_H

