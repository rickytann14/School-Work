#include <iostream>
#include <string>
#include "aircraft.h"
using namespace std;

Aircraft::Aircraft(){
	model = "none";
	make = "none";
	status = "none";
	seat_num = 0;
	tail_num = "none";
	range = 0;
}

void Aircraft::addModel(string mod){
	model = mod;
}

void Aircraft::addMake(string mak){
	make = mak;
}

void Aircraft::addstatus(string stat){
	status = stat;
}

void Aircraft::addseat(int seatnum){
	seat_num = seatnum;
}

void Aircraft::addtail(string tailnum){
	tail_num = tailnum;
}

void Aircraft::addrange(int dist){
	range = dist;
}

string Aircraft::getTailNum() const{
	return tail_num;
}

string Aircraft::getModel() const{
	return model;
}

string Aircraft::getMake() const {
	return make;
}

int Aircraft::getRange() const {
	return range;
}

int Aircraft::getSeatNum() const {
	return seat_num;
}

string Aircraft::getStatus() const {
	return status;
}