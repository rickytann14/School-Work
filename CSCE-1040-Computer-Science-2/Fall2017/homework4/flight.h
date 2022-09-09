#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
public:
	Flight();//Constructor
	void addPilot();//Add Functions
	void addCoPilot();
	void addCrew();
	void addTail();
	void addNumofPass();
	void addSTime();
	void addETime();
	void addStatus();
	void addSCode();
	void addECode();

	int getTail() const;//Accessor Functions
	int getPID() const;
	int getCOPID() const;
	int getCID() const;
	int getNumPass() const;
	int getECode() const;
	int getSCode() const;
	string getStat() const;
	string getStime() const;
	string getEtime() const;

private:
	string tailnum;
	int pilotid;
	int copilotid;
	vector<int> crewid;
	int num_pass;
	int ECode;
	int SCode;
	string status;
	string stime, etime;

};
#endif