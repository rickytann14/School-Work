#include "flights.h"

Flight pln;
Flights::Flights():plan(){
	flight_count = 0;
}

int Flights::upcount(){
	flight_count++;
	return 0;
}

int Flights::downcount(){
	flight_count--;
	return 0;
}

int Flights::getcount() const{
	return flight_count;
}

void Flights::addflight(){
	pln.addPilot();
	pln.addCoPilot();
	pln.addCrew();
	pln.addTail();
	upcount();
	plan.push_back(pln);
	cout << endl << endl;
}