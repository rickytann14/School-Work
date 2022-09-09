#ifndef FLIGHTS_H
#define FLIGHTS_H
#include "flight.h"

class Flights {
public:
	Flights();//Constructor
	void addflight();

	int upcount();
	int downcount();
	int getcount() const;
private:
	int flight_count;
	vector<Flight> plan;
};

#endif